/*
 Check Permutation: Given two strings, write a method to decide if one is a permutation of the 
other. 
In a Permutation of a String all Chars will be same - Only the positions can be different
E.g "abcd" - "abdc", "adbc", "adcb", "badc".... All are valid permuations of "abcd"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    // Approach 1
    // Using Hashmap (count Frequency of each char)
    // T.C -O(N)
    // S.C - O(N)

    bool isPermutation1(string first, string second)
    {
        if(first.length() != second.length())
            return false; // Not Permutations of Each other
        
        // Record Frequency of each char in both strings using Hashmap
        unordered_map<char,int> char_freq_first, char_freq_second;
        for(int i = 0; i < first.length(); i++)
        {
            char_freq_first[first[i]]++;
            char_freq_second[second[i]]++;
        }

        if(char_freq_first.size() != char_freq_second.size())
            return false; // Extra unique chars in one of the strings

        // Compare frequecies of each char in Both the hashmap
        for(auto &[c,first_freq] : char_freq_first)
            if(first_freq != char_freq_second[c])
                return false;
        
        return true;
    }

    // Approach 1 - Variation
    // Using count Vector

    // T.C - O(N)
    // S.C - (26)

    bool isPermutation2(string first, string second)
    {
        if(first.length() != second.length())
            return  false;

        vector<int> char_freq_first(26,0),char_freq_second(26,0);
        for(int i = 0; i < first.length(); i++)
        {
            char_freq_first[first[i]-'a']++;
            char_freq_second[second[i]-'a']++;
        }

        for(int i = 0; i < char_freq_first.size(); i++)
            if(char_freq_first[i] != char_freq_second[i])
                return false;

        return true;
    }

    // Approach 3
    // Using only one Count Vector 
    // At the end no char should be present

    // T.C - O(N)
    // S.C - O(26)

    bool isPermutation3(string first, string second)
    {
        if(first.length() != second.length())
            return false;
        
        vector<int> char_freq(26,0);
        for(int i = 0; i < first.length(); i++)
        {
            char_freq[first[i]-'a']++;
            char_freq[second[i]-'a']--;
        }

        for(int i = 0; i < char_freq.size(); i++)
            if(char_freq[i] != 0)
                return false;
        return true;

    }

};

int main()
{
    Solution s;
    cout << s.isPermutation1("abdc","badc");
    cout << s.isPermutation2("abdc","badc");
    cout << s.isPermutation3("abdc","badc");
}
