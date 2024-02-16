/*
 Sum Lists: You have two numbers represented by a linked list, where each node contains a single 
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a 
function that adds the two numbers and returns the sum as a linked list. 
EXAMPLE 
Input: ( 7 - > 1 - > 6) + ( 5 - > 9 - > 2 ) . That is, 617 + 295. 
Output: 2 -> 1 -> 9. That is, 912. 
FOLLOW UP 
Suppose the digits are stored in forward order. Repeat the above problem. 
EXAMPLE 
Input: ( 6 - > 1 - > 7 ) + ( 2 - > 9 -> 5 ) . That is, 617 + 295. 
Output: 9 -> 1 -> 2. That is, 912. 
*/

#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

    // Approach 1
    // Simply add the no's in 2 Linked List +  Maintain Carry bit
    // and store the result in a new linked list

    // T.C - O(N+M)
    // S.C - O(N+M)

    ListNode* addTwoNumbers(ListNode*first, ListNode*second)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *newList = dummyHead;
        int carry = 0, sum = 0, last_digit = 0;

        while(first && second)
        {
            sum = first->val + second->val + carry;
            last_digit = sum % 10;
            carry = sum/10;
            newList->next = new ListNode(last_digit);
            newList = newList->next;
            first = first->next;
            second = second->next;
        }

        while(first)
        {
            sum = first->val + carry;
            last_digit = sum % 10;
            carry = sum/10;
            newList->next = new ListNode(last_digit);
            first = first->next;
            newList = newList->next;

        }

        while(second)
        {
            sum = second->val + carry;
            last_digit = sum % 10;
            carry = sum/10;
            newList->next = new ListNode(last_digit);
            second = second->next;
            newList = newList->next;
        }

        //E.g 999 + 999
        if(carry != 0)
            newList->next = new ListNode(carry);

        return dummyHead->next;
    }

    // Approach 2
    // Without Using Extra Linked List

    // T.C - O(max(N,M), N = Length of List1, and M = Length of List2
    // S.C - O(max(N,M))

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) 
    {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* tail = l1;
        int carry_bit = 0,sum = 0 , last_digit;
        while(first && second)
        {
            last_digit = (first->val + second->val+carry_bit)%10;
            carry_bit = (first->val + second->val+carry_bit)/10;

            first->val = last_digit;
            tail = first;
            first = first->next;
            second = second->next;
        }

        while(first)
        {
            last_digit = (first->val + carry_bit)%10;
            carry_bit = (first->val +carry_bit)/10;

            first->val = last_digit;
            tail = first;
            first = first->next;

        }

        while(second)
        {
            last_digit = (second->val +carry_bit)%10;
            carry_bit = (second->val + carry_bit)/10;

            ListNode *new_node = new ListNode(last_digit);
            second = second->next;
            tail->next = new_node;
            tail = new_node;

        }

        if(carry_bit != 0)
        {
            ListNode *new_node = new ListNode(carry_bit);
            tail->next = new_node;
            tail = new_node;
        }
        
        return l1;
    }

    // Approach 2 - Cleaner + Concise
    // T.C - O(max (N,M))
    // S.C - O(N+M)

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) 
    {   ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        int carry = 0;
        while(carry || l1 || l2)
        {
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tail->next = new ListNode(carry%10); // Number
            tail = tail->next;
            carry /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return dummy->next;
    }

    // Folow Up - If List are stored in forward order
    // Simply reverse the lists and perform addition

    // Reverse Linked List using 3 Pointers
    // T.C - O(N)
    // S.C - O(1)

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = curr->next;

        while(curr)
        {
            curr->next = prev;
            prev = curr;
            curr = nextNode;

            if(curr)
                nextNode = curr->next;
        }
        // At end prev will point to head of reversed list
        return prev;
    }

    // If we don't want to reverse the list
    // We can start adding from last node, How ?
    // Using Recursion
    // But what if we have two list of different length (1→2→3→4) and (5→2)
    // It should be added like (4+2 , 3+5, 2+0, 1+0) = (1→2→8→6)
    // So we need to add padding of zeros in front of smaller list , so that they became equal
    // so (5→2) becomes (0→0→5→2))

    void addZerosPadding(ListNode* &first, int zerosCount)
    {
        ListNode *zero;
        for(int i = 0; i < zerosCount; i++)
        {
            zero = new ListNode(0);
            zero->next = first;
            first = zero;
        }
    }

    int findLength(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;
        while(curr)
        {
            len++;
            curr = curr->next;
        }
        return len;
    }

    void addList(ListNode *first, ListNode *second, int &carry, int sum)
    {
        if(!first && !second) // Reached the end
            return;

        addList(first->next,second->next,carry,sum);
        sum += first->val + second->val + carry;
        carry = sum / 10;
        first->val = sum % 10;
    }

    ListNode *addTwoNumbers3(ListNode *first, ListNode *second)
    {
        int firstLen = findLength(first);
        int secondLen = findLength(second);

        int diff = abs(firstLen - secondLen);
        if(diff != 0) // Both are not equal
        {
            if(firstLen < secondLen)
                addZerosPadding(first,diff);
            else
                addZerosPadding(second,diff);
        }

        int carry = 0;
        addList(first,second,carry,0);
        if(carry != 0)
        {
            ListNode *newHead = new ListNode(carry);
            newHead->next = first;
            first = newHead;
        }
        
        return first;
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
    ListNode *first = new ListNode(9);
    first->next = new ListNode(9);
    first->next->next = new ListNode(9);

    ListNode *second = new ListNode(9);
    // second->next = new ListNode(9);
    // second->next->next = new ListNode(9);

    ListNode *node = s.addTwoNumbers(first,second);
    s.display(node);

    ListNode *nod = s.addTwoNumbers3(first,second);
    s.display(nod);

}