/*
 Palindrome: Implement a function to check if a linked list is a palindrome. 
 1→2→3→2→1 is a palindrome (Same both from front and back)
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
    // Using Recursion
    // Reach to the end of list, and while back tracking compare the nodes

    // T.C - O(N)
    // S.C - O(N) - Recursive Stack Space

    ListNode *first;
    bool dfs(ListNode *last)
    {
        if(!last) // Base case, reached the end
            return true; 
        
        if(!dfs(last->next))
            return false;
        
        if(last->val != first->val)
            return false;
        first = first->next;
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        first = head;
        return dfs(head);
    }

    // Approach 2
    // Reverse the list + then compare them from start
    // Just compare first length/2 nodes (No need to compare whole list)
    // 1→2→3→2 and 2→3→2→1
    // Iterative 

    // T.C -O(N)
    // S.C - O(N) - Storing the Reverse list

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previous = NULL;
        ListNode *current = head;
        ListNode *nextNode = current->next;

        while(current)
        {
            current->next = previous;
            previous = current;
            current = nextNode;
            if(current
            )
                nextNode = current->next;
        }
        return previous;
    }

    int getLength(ListNode *head)
    {
        int length = 0;
        ListNode *current = head;
        while(current)
        {
            current = current->next;
            length++;
        }
        return length;
    }

    ListNode *copyList(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *current = dummyHead;
        
        while(head)
        {
            current->next = new ListNode(head->val);
            head = head->next;
            current = current->next;
        }
        return dummyHead->next;
    }

public:
    
    bool isPalindrome1(ListNode *head)
    {
        int length = getLength(head);
        if(length == 1)
            return true;

        ListNode *listCopy = copyList(head);
        ListNode *reversedList = reverseList(listCopy);
        int idx = 0;

        while(idx < length/2)
        {
            if(head->val != reversedList->val)
                return false;
            head = head->next;
            reversedList = reversedList->next;
            idx++;
        }
        return true;
    }

    
    // Approach 2 - Optimisation
    // Do we really need to copy a list and then reverse it
    // We essentially are comparing first length/2 nodes

    // Can we do something like , keep first half of list as it is
    // and reverse the second half and then compare first and second half
    // 1→2→3→2→1 = (1→2) + (1→2→3) = 1→2→2→1→3

    // T.C - O(N)
    // S.C - O(1)

    bool isPalindrome2(ListNode *head)
    {
        // Travel till length/2
        int length = getLength(head);
        if(length == 1)
            return true;

        ListNode *current = head;
        for(int i = 0; i < length/2 -1; i++)
            current = current->next;
        
        // Now reverse the second half starting from current and link them
        ListNode *secondHalfHead = reverseList(current->next);
        current->next =  secondHalfHead;

        // Now compare them
        ListNode *firstHalfHead = head;
        for(int i = 0; i < length/2; i++)
        {
            if(firstHalfHead->val != secondHalfHead->val)
                return false;
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }
        return true;
    }

};

int main()
{
    Solution s;
    ListNode *first = new ListNode(8);
    first->next = new ListNode(8);
    first->next->next = new ListNode(9);
    cout << s.isPalindrome(first) << endl;
    cout << s.isPalindrome1(first) << endl;
    cout << s.isPalindrome2(first) << endl;
}
