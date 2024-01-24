/*

String Compression: Implement a method to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the 
"compressed" string would not become smaller than the original string, your method should
return the original string. You can assume the string has only uppercase and lowercase letters (a - z). 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:

        // Approach 1
        // Count consecutive frequency of each character
        // As soon as you encounter a different char - Reset count and insert char + it's freq 
        // in compressed string

        // T.C - O(N)
        // S.C - O(N*K) K = no. of consecutive chars in String 
        // e.g "aabbaabbcdef" - has [a,b,a,b,c,d,e,f] = 8 consecutive unique chars

        string compress(string sequence)
        {
            string compressed_string;
            int count_freq = 1;

            for(int i = 1; i < sequence.length(); i++)
            {
                if(sequence[i] == sequence[i-1])
                    count_freq++;
                
                else
                {
                    compressed_string.push_back(sequence[i-1]);
                    compressed_string += to_string(count_freq);
                    // Concatenation will create a new string - Not space efficient
                    count_freq = 1;
                }
            }

            if(count_freq != 0) // Last char is not compressed
            {
                compressed_string.push_back(sequence.back());
                compressed_string += to_string(count_freq);
            }

            if(compressed_string == sequence)
                return sequence;
            return compressed_string;
        }

        // Approach 1 - Optimisation
        // Checking in Advance length of compressed string and if it's == sequence.length()
        // return sequence
        // else return compressed string

        // T.C - O(N)
        // S.C - O(N)

        int count_compression(string sequence)
        {
            int count_freq = 1, compressed_length = 0;

            for(int i = 1; i < sequence.length(); i++)
            {
                if(sequence[i] == sequence[i-1])
                    count_freq++;
                
                else
                {
                    // log10(count_Freq) + 1 = no. of digits in count_freq
                    compressed_length += 1 + log10(count_freq) + 1;
                    count_freq = 1;
                }
            }

            if(count_freq != 0) // Last char is not compressed
               compressed_length += 1 + log10(count_freq) + 1;
            
            return compressed_length;

        }

        string compress1(string sequence)
        {
            int final_length = count_compression(sequence);
            
            if(final_length == sequence.length())
                return sequence;
            
            string compressed_string;
            int count_freq = 1;
            for(int i = 1; i < sequence.length(); i++)
            {
                if(sequence[i] == sequence[i-1])
                    count_freq++;
                
                else
                {
                    // More efficient way to concatenation
                    compressed_string.push_back(sequence[i-1]);
                    string freq = to_string(count_freq);
                    for(char &c : freq)
                        compressed_string.push_back(c);

                    count_freq = 1;
                }
            }

            if(count_freq != 0) // Last char is not compressed
            {
               compressed_string.push_back(sequence.back());
                string freq = to_string(count_freq);
                for(char &c : freq)
                    compressed_string.push_back(c);
            }
            
            return compressed_string;

        }

};

int main()
{
    Solution s;
    cout << s.compress("aabcd") << endl;
    cout << s.compress1("aabcd") << endl;
    cout << s.compress("aaabbbaaabbabb") << endl;
    cout << s.compress1("aaabbbaaabbabb") << endl;
    cout << s.compress("AAAbbbaaaBBabb") << endl;
    cout << s.compress1("AAAbbbaaaBBabb") << endl;

}