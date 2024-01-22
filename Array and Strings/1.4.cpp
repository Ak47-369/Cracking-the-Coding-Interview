/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. 
EXAMPLE 
Input: Tact Coa 
Output: True ( permutations : "taco cat" , "at co eta" , etc . ) 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // Approach 1
        // Using Hashmap
        // Can contain both upper and lower case character - Treat them as one + Ignore white spaces
        // Count frequency of each character 
        // IF length of string is odd - Every char's frequency should be even except one
        // If length of string is even - Every char's frequency should be even

        // T.C - O(N)
        // S.C - O(N)
        bool isPermutationPalindrome(string sequence)
        {
            // Key = char and value = it's frequency (how many times it's present in string)
            unordered_map<char,int> chars_freq;
            int odd_freq = 0, even_freq = 0, count_whiteSpaces = 0;

            for(char &c : sequence)
            {
                if(c == ' ')
                    count_whiteSpaces++;

                else if(isupper(c)) // If char is in upper case - convert to lower case
                    chars_freq[tolower(c)]++;
                else 
                    chars_freq[c]++;
            }

            for(auto &[c,freq] : chars_freq)
            {
                if(freq%2 == 0) 
                    even_freq++;
                else
                    odd_freq++;
            }

            
            int length = sequence.length() - count_whiteSpaces;

            if(length % 2 == 0) // Even length
                return (odd_freq == 0);
        
            return (odd_freq == 1);
            
        }

        // Approach 1 Variation
        // Counting Frequency using Count vector

        // T.C - O(N)
        // S.C - O(26)

        bool isPermutationPalindrome1(string sequence)
        {
            vector<int> chars_freq(26,0);
            int odd_freq = 0, even_freq = 0, count_whiteSpaces = 0;

            for(char &c : sequence)
            {
                if(c == ' ')
                    count_whiteSpaces++;

                else if(isupper(c)) // If char is in upper case - convert to lower case
                    chars_freq[tolower(c)-'a']++;
                else 
                    chars_freq[c-'a']++;
            }

            for(int &freq : chars_freq)
            {
                if(freq != 0)
                {
                    if(freq%2 == 0) 
                        even_freq++;
                    else
                        odd_freq++;
                }
               
            }

            
            int length = sequence.length() - count_whiteSpaces;

            if(length % 2 == 0) // Even length
                return (odd_freq == 0);
        
            return (odd_freq == 1);
        }

        // Approach 2 - Using XOr to flip the bit
        // If we look carefully we only need to find out the count of odd_freq elements
        // Since range is fixed (26 alphabets) 
        // and We represents an integer in 32 bits - so can we use this fact to count odd freq elements
        // Set bit(1)- represents a char is present in string 
        // Unset bit (0) - represents a char is not present in string
        // E.g 00000000101 - reprsents c and a are present odd no. of time in string
        // Start from 00000.... and when you encounter a char flip bit present at that index, do that repreatedly
        // At the end of string traversal if any bit is 1 - means that char is present odd no. of times
        // Because Intially we started from 0, 
        // E.g aaa -> ..00000 -> ...00001 -> ...00000 -> ....000001 (a is prsent 3 times(odd))

        // T.C - O(N)
        // S.C - O(1)

        void flip_bit(int &num, char c)
        {
            int idx = c - 'a'; // Index start from Right 
            int mask = (1 << idx);
            num = mask^num;
        }

        bool isPermutationPalindrome2(string sequence)
        {
            int num = 0, count_whiteSpaces = 0;
            for(char &c : sequence)
            {
                if(c == ' ')
                    count_whiteSpaces++;
                else if(isupper(c))
                    flip_bit(num,tolower(c));
                else
                    flip_bit(num,c);
            }
            
            int length = sequence.length() - count_whiteSpaces;
            int odd_freq = __builtin_popcount(num);

            if(length % 2 == 0)
                return (odd_freq == 0);
            return (odd_freq == 1);
            
        }

};

int main()
{
    Solution s;
    cout << s.isPermutationPalindrome("Tact Coa") << endl;
    cout << s.isPermutationPalindrome1("City of STars stARS OF cITY") << endl;
    cout << s.isPermutationPalindrome2("Hola Amigo") << endl;

}