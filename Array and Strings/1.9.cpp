/*

String Rotation: Assume you have a method isSubstring which checks if one word is a substring 
of another. Given two strings, s 1 and s2, write code to check if s2 is a rotation of sl using only one 
call to isSubstring (e.g., "waterbottle"is a rotation of"erbottlewat"). 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
        // Approach 1
        // To find whether a string s2 is a rotation of s1 we need to check all chars in s2 to s1 in a circular fashion
        // E.g s1 = "wwwlm" and s2 = "wlmww" - We find first occurence of w in s1 → lets say ith index (Here i = 0)
        // Match (i+1) th index w != l → Do not matches → Find next occurence of w in s1 → its index 1
        // Match (i+1) 2nd index w != l → Do not matches → Find next occurence of w in s1 → its index 2
        // Match (i+1) 3rd index l == l → m == m → Now we reached the end in s1 → So start from begining again
        // w == w → w == w → All chars matches so yes s2 is a rotation of s1

        // Since it's given that we can call isSubstr() function only once → We somehow have to find a way , that we don't
        // need to traverse in a circular way → Just add s1 after s1
        // Now s1 becomes → "wwwlmwwwlm"
        // Now we can easily check whether "wlmww" is a substring of s1 or not in only one function call

        // T.C - O(N)
        // S.C - O(N)

        bool isSubstr(string s1,string s2) // T.C - O(N)
        {
            int n = s1.length(), m = s2.length();
            if(m > n)
                return false;

            // Using Sliding window of s2.length() to check whether s2 is a substring of s1 or not
            for(int i = 0; i <= n - m; i++)
                if(s1.substr(i,m) == s2)
                    return true;
            return false;
        }

        bool isRotation(string s1, string s2)
        {
            if(s1.length() != s2.length())
                return false;
            
            string doubled_s1 = s1 + s1;
            if(isSubstr(doubled_s1,s2))
                return true;
            
            return false;
        }


        // In Approach 2 → Main implementation is of timesRotated
        // timesRotated → will return the no. of rotations required to rotate s2 so that s2 become s1
        // and if it's not possible return -1
        // And I want to do this implementation in O(1) Space (i.e Without doing s1+s1 or s1+s2 or s2+s2)
        // Currently I am not able to implement this → If you have implemented it (Do raise a Pull Request)

        // Approach 2  
        // Do we really need to double the string s1 ?
        // Ultimately we have to find that whether a s2 is a Rotated Version of s1
        // Let's suppose it is a Rotated Version of s1 → then how should s2 should look like
        // E.g s1 = "supermercado" and s2 = "cadosupermer" → "cado|supermer" Rotated 4 times (r = 4)
        // secondHalf = s2.substr(r,n-r) → s2.substr(4,8) and firstHalf = s2.substr(0,r) → s2.substr(0,4)
        // secondHalf = supermer and firstHalf = cado
        // Now check if secondHalf + firstHalf = supermer+cado = "supermercado"
        // is a substring of of "supermercado"

        // Now our problem is reduced to only find the how many time a string is rotated ?
        // But s2 is not a rotated version of s1 then we 

        /*
        int timesRotated(string s1, string s2)
        {
            int n = s1.length(), m = s2.length();
            if(s1.length() != s2.length())
                return -1;

            for(int i = 0; i < s1.length(); i++)
            {
                bool rotated = true;
                for(int j = 0; j < s2.length(); j++)
                {
                    if(s1[j+i] != s1[j])
                    {
                        rotated = false;
                        break;
                    }
                }

                if(rotated)
                    return m-i ; // Rotated m - itimes (Split index = i)
            }
            return -1; // s2 is not a Rotation of s1
        }

        bool isRotation1(string s1, string s2)
        {
            if(s1.length() != s2.length())
                return false;
            
            int rotations = timesRotated(s1,s2);
            cout << "Rotations " << rotations << endl;
            if(rotations == -1) 
                return false;
            
            // Check if secondHalf + first Half == s1
            if(isSubstr(s1,s2.substr(rotations) + s2.substr(0,rotations)))
                return true;
            return false;
        }

        */
};


int main()
{
    Solution s;
    cout << s.isRotation("wwwlmw","wwlmww") << endl;
    cout << s.isRotation("wwwlm","lmwww") << endl;
    cout << s.isRotation("wwwlm","wwwlm") << endl;
}