/*
 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string 
has sufficient space at the end to hold the additional characters, and that you are given the "true" 
length of the string. (Note: If implementing in Java, please use a character array so that you can 
perform this operation in place.) 
EXAMPLE 
Input: "Mr J ohn Smith  ", truelength = 13 
Output: "Mr%20John%2 05mith"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // Approach 1
        // Using 2 Pointers
        // Shift the chars to end and place "%20" in place of space's indices
        // T.C - O(N)
        // S.C - O(1)

        void Urlify(string sequence, int length)
        {
            // Track whitespace indices
            int prev = length-1, curr = sequence.length()-1;
            while(prev >= 0)
            {
                if(sequence[prev] == ' ') // Place %20
                {
                    sequence[curr--] = '0';
                    sequence[curr--] = '2';
                    sequence[curr--] = '%';

                    // Now prev == curr so update previous
                    prev = prev-1;
                }
                sequence[curr--] = sequence[prev--];
            }
            cout << sequence << endl;
                
        }
};

int main()
{
    Solution s;
    s.Urlify("Mr John Smith    ",13);
    s.Urlify(" MrJohnSnow  ",11);
    s.Urlify("Dracula   ",8);
}
