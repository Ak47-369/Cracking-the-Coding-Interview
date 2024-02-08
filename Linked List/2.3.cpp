/*
Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but 
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to 
that node. 
EXAMPLE 
Input: the node c from the linked list a - >b - > c - >d - >e - >f 
Result: nothing is returned, but the new linked list looks like a - >b- > d - >e- >f 
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
    // First find the length of List then find Middle node and delete it

    // T.C - O(N)
    // S.C - O(1)
    int findLength(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;
        while(curr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }

    void deleteMiddle(ListNode *head)
    {
        if(!head->next || !head->next->next) // <= 2 Elements
            return; // Can't Delete

        int middle = findLength(head)/2;
        int currIdx = 1;
        ListNode *curr = head;

        while(currIdx < middle)
        {
            curr = curr->next;
            currIdx++;
        }

        // Delete the middle node
        curr->next = curr->next->next;
    }

    // Approach 2
    // Using fast and slow pointer or Tortoise and Hare
    // In this Approach we don't need to find the length of List
    // Start both fast and slow pointer from starting of List
    // Fast move by 2 node, and slow move by 1 node in each step
    // When fast reach the end , Slow pointer will point to middle of the List

    // T.C - O(N/2)
    // S.C - O(1)

    void deleteMiddle1(ListNode *head)
    {
        if(!head->next || !head->next->next) // <= 2 Elements
            return; // Can't Delete

        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now slow points to middle node, delete it
        prev->next = slow->next;
    }

    // Approach 3
    // If we are directly given the middle node (Not given the Head of Linked List)
    // Simply copy the data of next node to curr node and delete next node
    // Eg a→b→c→d → a→b→d→d → a→b→d

    // T.C - O(1)
    // S.C - O(1)

    void deleteMiddle2(ListNode *middle)
    {
        if(!middle || !middle->next)
            return; // Can't delete first or last node

        middle->val = middle->next->val;
        middle->next = middle->next->next;
    }

    void display(ListNode *head)
    {
        ListNode *curr = head;
        while(curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }

};

int main()
{
    Solution s;
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    s.display(list);
    // s.deleteMiddle(list);
    // s.deleteMiddle1(list);
    // s.deleteMiddle2(list->next->next);
    s.display(list);


}