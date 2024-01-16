/*
 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you 
cannot use additional data structures? 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Approach 1
    // Bruteforce 
    // Check for each index (i) whether it exists in in [i+1,n] or not
    // T.C - O(N^2)
    // S.C - O(1)

    bool isUnique1(string sequence)
    {
        for(int i = 0; i < sequence.length(); i++)
            for(int j = i+1; j < sequence.length(); j++)
                if(sequence[i] == sequence[j]) // Duplicate exists
                    return false;
        return true;
    }

    // Approach 2
    // Using Sorting
    // If 2 adjacent characters are same - Duplicate exists
    // T.C - O(N log N)
    // S.C - O(log N)

    bool isUnique2(string sequence)
    {
        sort(sequence.begin(),sequence.end());
        for(int i = 1; i < sequence.length(); i++)
            if(sequence[i] == sequence[i-1])
                return false;
        return true;
    }

    // Approach 3
    // Using Hashet - Record the chars which are already present as you traverse the string
    // T.C - O(N)
    // S.C  - O(26)

    bool isUnique3(string sequence)
    {
        unordered_set<char> unique_chars;
        for(char &c : sequence)
        {
            if(!unique_chars.count(c))
                unique_chars.insert(c);
            else
                return false; // Already present
        }
        return true;
    }

    // Approach 3 - Variation 
    // Using count Vector

    // T.C - O(N)
    // S.C - O(26)

    bool isUnique3a(string sequence)
    {
        // Intialize frequecy of each char to 0
        vector<int> chars_freq(26,0); 
        for(char &c : sequence)
        {
            if(chars_freq[c-'a'] != 0)
                return false; // Duplicate exists
            else
                chars_freq[c-'a']++;
        }
        return true;
    }

    // Approach 3 - Variation
    // Using Hashmap

    // T.C - O(N)
    // S.C - O(26)

    bool isUnique3b(string sequence)
    {
        unordered_map<char,int> char_freq;
        for(char &c : sequence)
        {
            if(!char_freq.count(c))
                char_freq[c]++;
            else 
                return false;
        }
        return true;

    }

     // Approach 4 - Very Similar to Approach 3
    // Using BitManiuplation
    // Using the fact that for storing the integer we use 32 bits and we need 26 bits
    // to keep track of  characters which already present
    // If i th bit is set - means ith char is already present in string
    // If i th bit is unset - ith char is not present in string
    // e.g = "abzdc" - count = 10000000000000000000001111

    bool isUnique4(string sequence)
    {
        int count = 0; // 0000...32 times
        for(char &c : sequence)
        {
            int index = c -'a';
        //     int num = pow(2,index); 

        // To represent j (index = 10) 1 >> 9 -> 1000000000
        // Efficient way of generating num
            int num = (1 << (index-1));
        
            if((count & num) > 0) // index th bit is set - Char is already present
                return false;
            else
                count = (count | num); // Set the index th bit
        }
        return true;
    }


};

int main()
{
    Solution s;
    string sequence = "abcrdefghyz";
    cout << s.isUnique1(sequence) << endl;
    cout << s.isUnique2(sequence) << endl;
    cout << s.isUnique3(sequence) << endl;
    cout << s.isUnique3a(sequence) << endl;
    cout << s.isUnique3b(sequence) << endl;
    cout << s.isUnique4(sequence) << endl;
}