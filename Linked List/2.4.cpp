/*
 Partition: Write code to partition a linked list around a value x, such that all nodes less than x come 
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need 
to be after the elements less than x (see below). The partition element x can appear anywhere in the 
"right partition"; it does not need to appear between the left and right partitions. 
EXAMPLE 
Input: 3 - > 5 - > 8 - > 5 - > 10 [partition = 5]
Output: 3 - > 1 - > 2 - >|Partition| 10 - > 5-> 5 -> 8

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{

public:
    
    // Approach 1
    // In 2 Passes
    // In First Pass - Add all elements < x
    // In Second Pass - Add all elements >= x

    // T.C - O(N)
    // S.C - O(N) - Creating a new Linked List

    ListNode * partition(ListNode *head, int x)
    {
        ListNode *curr = head;
        ListNode *dummyHead = new ListNode(0);
        ListNode *newList = dummyHead;


        // Insert all elements < x
        while(curr)
        {
            if(curr->val < x)
            {
                newList->next = new ListNode(curr->val);
                newList = newList->next;
            }
            curr = curr->next;
        }

        // Insert all elements >= x
        curr = head;
        while(curr)
        {
            if(curr->val >= x)
            {
                newList->next = new ListNode(curr->val);
                newList = newList->next;
            }
            curr = curr->next;
        }

        return dummyHead->next;
    }

    // Approach 1 - Variation
    // In Single Pass
    // Build two seperate list - One for < x and one for >= x values
    // Then merge them later

    // T.C - O(N)
    // S.C  O(N)

    ListNode *partition1(ListNode *head, int x)
    {
        ListNode *curr = head;
        ListNode *dummyFirst = new ListNode(0);
        ListNode *dummySecond = new ListNode(0);
        ListNode *firstList = dummyFirst;
        ListNode *secondList = dummySecond;

        while(curr)
        {
            if(curr->val < x)
            {
                firstList->next  = new ListNode(curr->val);
                firstList = firstList->next;
            }

            else
            {
                secondList->next = new ListNode(curr->val);
                secondList = secondList->next;
            }

            curr = curr->next;
        }

        // Now merge them
        firstList->next = dummySecond->next;
        return dummyFirst->next;
    }

    // Approach 3
    // Add all elements < x at front of list 
    // At the end all elements < x will be in first half and >=x  in second half
    // Insertion at Head takes O(1)

    // T.C - O(N)
    // S.C - O(1)

    ListNode *partition2(ListNode *head, int x)
    {
        //Start from 2nd node, because even if first node is < x
        // It's already at head, no need to add it to head again
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nextNode = NULL;
        if(curr->next)
            nextNode = curr->next;
        while(curr)
        {
            if(curr->val < x)
            {
                // Add curr to head
                curr->next = head;
                head = curr; // New Head

                // Link prev to next
                prev->next = nextNode;
            }

            else 
                prev = prev->next;

            curr = nextNode;
            if(nextNode)
                nextNode = nextNode->next;
        }
        return head;

    }


    void display(ListNode *head)
    {
        ListNode *curr = head;
        while(curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << " null " << endl;
    }

};

int main()
{
    Solution s;
    ListNode* list = new ListNode(4);
    list->next = new ListNode(5);
    list->next->next = new ListNode(1);
    list->next->next->next = new ListNode(10);

    auto newNode = s.partition(list,5);
    s.display(newNode);
    auto node = s.partition1(list,5);
    s.display(node);

    auto newnode = s.partition2(list,5);
    s.display(newnode);
}