/*
 One Away: There are three types of edits that can be performed on strings: insert a character, 
remove a character, or replace a character. Given two strings, write a function to check if they are 
one edit (or zero edits) away. 
EXAMPLE 
pale , ple - > true 
pales , pale - > true 
pale , bale - > true 
pale , bake - > false 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:

        // Approach 1
        // Checking whether by performing any of 3 operation can we make first = second or not

        // T.C - O(N)
        // S.C - O(1)

        bool oneEditReplace(string first, string second)
        {
            bool foundDifference = false;
            for(int i = 0; i < first.length(); i++)
            {
                if(first[i] != second[i]) 
                {
                    if(foundDifference)
                        return false; // Second Difference
                    foundDifference = true; // It's first difference
                }
            }
            return true; // Can convert first into string by 1 Insertion
        }

        bool oneEditInsertion(string first, string second)
        {
            int index1 = 0, index2 = 0;
            while(index1 < first.length() && index2  < second.length() )
            {
                if(first[index1] != second[index2]) // We need to insert a char in first
                {
                    if(index1 != index2) // We already have inserted a char - Can only pefrom 1 insert option
                        return false;
                    index1++; // Required char was inserted at index1 
                }

                else
                {
                    index1++;
                    index2++;
                }
            }
            return true;
        }
        bool isOneAway(string first, string second)
        {
            // More than 1 edit away
            if(abs((int)first.length() - (int)second.length()) > 1)
                return false;
            
            if(first.length() == second.length()) // Can only perfrom Repalcement
                return oneEditReplace(first,second);
            
            else if(first.length() -1 == second.length())
                return oneEditInsertion(first,second);
            else
                return oneEditInsertion(second,first);
            
            return false;
        }

        // Approach 2
        // Using Count Vector
        // This is extension of above problem - Check if both string are one Edit Away 
        // When order is not important 
        // e.g "bale" and "aled" - are one Edit Away
        
        // While you traverse first string , if a char is present increase it frequency
        // While you traverse second string, if a char is present decrease it frequency
        // So if at the end freq af all chars is zero -> means both string are equivalent (Permutations of each other)
        // E.g "abdc" and "dcba" - Zero Away
        // And if at the end there are 2 chars with non zero frequency or 1 char with freq > 1 
        // They are not equaivalent - Not One Away
        // E.g "raat" and "daat" - At end [r - 1] and [d - -1] - Replace 'r' with 'd' or vice versa - They are one Away
        // E.g "pade" and "bafe" - At end [p - 1,d - 1] and [b - -1, f - -1] - Not one Away
        // E.g "ppdp" and "depr" - At end [p - 2] and [r - -1] - Cant replace 2 p's - Not one away

        // T.C - O(N)
        // S.C - O(26)

        bool isOneAway1(string first, string second)
        {
            // More than 1 Edit Away
            if(abs((int)first.length() - (int)second.length()) > 1)
                return false;
            
            vector<int> char_freq(26,0);
            int unmatched_chars = 0;
            for(char &c : first)
                char_freq[c-'a']++;
            
            for(char &c : second)
                char_freq[c-'a']--;
            
            for(int &freq : char_freq)
                if(freq > 0)
                    unmatched_chars++;
            
            if(unmatched_chars > 1)
                return false;
            return true;

        }

};

int main()
{
    Solution s;
    cout << s.isOneAway("bale","rtle") << endl;
    cout << s.isOneAway1("bale","rtle") << endl;
    cout << s.isOneAway("pale","ple") << endl;
    cout << s.isOneAway1("pale","ple") << endl;
}