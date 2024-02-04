/*
 Remove Duplicates: Write code to remove duplicates from an unsorted linked list. 
FOLLOW UP 
How would you solve this problem if a temporary buffer is not allowed? 
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
        // Use a Hashset to keep track of unique_nodes + Create a new Unique List
        // If curr nodes is already present - Means It's a duplicate don't add to new list

        // T.C - O(N)
        // S.C - O(2N) - Creating a new list + Hashset
 
        ListNode* removeDuplicates(ListNode *head)
        {
            unordered_set<int> unique_nodes;
            ListNode *dummyHead = new ListNode(0);
            ListNode *dummyCurr = dummyHead;
            ListNode *curr = head;
            while(curr)
            {
                if(!unique_nodes.count(curr->val))
                {
                    dummyCurr->next = new ListNode(curr->val);
                    dummyCurr = dummyCurr->next;
                    unique_nodes.insert(curr->val);
                }
                curr = curr->next;
            }

            return dummyHead->next;
        }

        // Approach 2
        // Instead of Creating a new List → Removing duplicate from given list
        // To delete a node → We need previous node

        // T.C - O(N)
        // S.C - O(N)
        ListNode* removeDuplicates1(ListNode *head)
        {
            unordered_set<int> unique_nodes;
            ListNode *prev = head;
            ListNode *curr = head;

            while(curr)
            {
                if(!unique_nodes.count(curr->val))
                {
                    if(prev != curr)
                        prev->next = curr;
                    prev = curr;
                    unique_nodes.insert(curr->val);
                }
                curr = curr->next;
            }

            if(prev->next != NULL) // Add Null to prev->next → To Mark the end of List
                prev->next = NULL;
            
            return head;
        }

        // Approach 3
        // Not using an Extra Space
        // Check for each node → If a node with same value exists in Right of curr node
        // Mean it's a duplicate → Don't add this to list
        // If node with same value don't exist  in Right of curr node → It's unique
        // Add it to list

        // T.C - O(N^2)
        // S.C - O(1)
        bool isDuplicate(int value,ListNode *curr)
        {
            while(curr)
            {
                if(curr->val == value) // Duplicate
                    return true;
                curr = curr->next;
            }
            return false;
        }

        ListNode* removeDuplicates2(ListNode *head)
        {
            ListNode *dummyHead;
            ListNode *prev = head;
            ListNode *curr = head;
            bool isNewHead = false;
            while(curr)
            {
                if(!isDuplicate(curr->val,curr->next))
                {
                    if(!isNewHead)
                    {
                        dummyHead = prev;// first non duplicate → It's the new head
                        isNewHead = true;
                    }
                    
                    else
                    {
                        // Prev_non duplicate -> next = curr (Non duplicate)
                        prev->next = curr;
                        prev = curr; // Update Prev
                    }
                }

                else // Duplicate
                    prev = prev->next;
                curr = curr->next;
            }
            return dummyHead;

        }

        // Approach 3 - Variation
        // Not using Extra Space
        // For each node → Insert it into list and delete all it's duplicate from list

        // T.C - O(N^2)
        // S.C - O(1)

        ListNode* removeDuplicates3(ListNode *head)
        {
            ListNode *dummyHead = head;
            ListNode *prev = head;

            while(prev)
            {
                ListNode *curr = prev;
                // Delete all it's duplicate from list
                while(curr && curr->next)
                {
                    if(curr->next->val == prev->val)
                        curr->next = curr->next->next;
                    else
                        curr = curr->next;
                }
                prev = prev->next;
            }
            return dummyHead;
        }

        void display (ListNode *head)
        {
            while(head)
            {
                cout << head->val << " -> ";
                head = head->next;
            }
            cout << "NULL";
            cout << endl;
        }
};

int main()
{
    ListNode *list = new ListNode(3);
    list->next = new ListNode(3);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(2);
    // List = 2→2→3→3

    Solution s;
    auto newList = s.removeDuplicates1(list);
    auto newList2 = s.removeDuplicates1(list);
    auto newList3 = s.removeDuplicates3(list);
    
    s.display(newList);
    s.display(newList2);
    s.display(newList3);
}