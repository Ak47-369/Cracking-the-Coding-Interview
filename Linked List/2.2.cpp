/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution{

    public:
        
        // Approach 1
        // Kth node from last = n-k+1 th node from start
        // Calculate length of Linked list and then find n-k+1 th node from start

        // T.C - O(N)
        // S.C - O(1)

        ListNode* findKthNode(ListNode* head, int k)
        {
            int length = 0;
            ListNode *dummyHead = head;
            ListNode *curr = head;
            while(curr)
            {
                length++;
                curr = curr->next;
            }

            int fromStart = length - k+1;
            int curr_idx = 1;
            curr = dummyHead;
            while(curr_idx < fromStart)
            {
                curr = curr->next;
                curr_idx++;
            }

            // Now we are at our kth node
            return curr;
        }

        // Approach 2
        // Reverse the list (using 3 Pointers prev ,curr and next)
        // + Find kth node from start

        // 1→2→3→4, prev = null, curr = 1, next = 2
        // null <- 1, 2→3→4
        // null <- 1 <-2  3→4
        // null <- 1 <- 2 <-3, 4→null
        // null <- 1 <- 2 <- 3 <-4, Now curr == null → Stop


        // T.C - O(N)
        // S.C - O(1)

        // Return head of reversed list
        ListNode * reverseList(ListNode *head)
        {
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *next = curr->next;

            while(curr)
            {
                curr->next = prev;
                prev = curr;
                curr = next;

                if(curr)
                    next = curr->next;
            }
            return prev;
        }

        ListNode * findKthNode1(ListNode *head, int k)
        {
            ListNode *newHead = reverseList(head);
            ListNode *curr = newHead;
            while(--k > 0)
                curr = curr->next;
            return curr;
        }

        // Approach 3 
        // Recursive 
        // Start counting from end → If count == k , return node
        
        // T.C - O(N)
        // S.C - O(N) - Recursive Stack Space

        ListNode *kthNode;
        int findNode(ListNode *head,int k)
        {
            if(!head)
                return 0;

            int index = findNode(head->next, k)+1;
            if(index == k)
            {
                kthNode = head;
                return index;
            }
            return index;
        }

        ListNode* findKthNode2(ListNode *head, int k)
        {
            findNode(head,k);
            return kthNode;
        }

        // Approach 3 - By passing counter by reference

        // T.C - O(N)
        // S.C - O(N)
        ListNode *findKthNode3(ListNode *head, int &k)
        {
            if(!head)
                return NULL;
            
            ListNode *node = findKthNode3(head->next,k);
            k--;
            if(k == 0)
                return head;
            return node;
        }

        // Approach 4 - Using 2 Pointers
        // Set 2 pointers first,second , k node apart
        // Initially first will point to first node and second will point to the kth node 
        // Traverse the Linkedlist, when second reach the end
        // first will point to (len - k) th node i.e kth node from last

        // T.C- O(N)
        // S.C - O(1)

        ListNode *findKthNode4(ListNode *head, int k)
        {
            ListNode *first = head;
            ListNode *second = head;

            // Move second to kth node from start
            for(int i = 0; i < k; i++)
                second = second->next;
            
            // Now move both first and start
            while(second)
            {
                first = first->next;
                second = second->next;
            }

            // Now first will point to the kth node from end
            return first;
            
        }

};

int main()
{
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(19);
    list->next->next->next = new ListNode(4);

    Solution s;
    ListNode *kth = s.findKthNode(list,4);
    cout << kth->val << endl;
    // ListNode *kthNode = s.findKthNode1(list,4);
    // cout << kthNode->val << endl;

    // ListNode *finalNode = s.findKthNode2(list,3);
    // cout << finalNode->val << endl;

    int k = 4;
    // ListNode *node = s.findKthNode3(list,k);
    // cout << node->val << endl;

    ListNode *n = s.findKthNode4(list,k);
    cout << n->val;



}