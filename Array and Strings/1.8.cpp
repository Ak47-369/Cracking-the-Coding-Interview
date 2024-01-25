/*
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and 
column are set to 0. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

        // Approach 1 - Bruteforce
        // Using an Extra Matrix
        // While you traverse the matrix if curr cell[i,j] = 0 set whole row[i] and col[j] to zero 
        // In our Result Matrix 

        // T.C - O(N*M)
        // S.C - O(N*M)

        vector<vector<int>> set_zero(vector<vector<int>> &matrix)
        {
            int rows = matrix.size(), cols = matrix[0].size();
            vector<vector<int>> result (rows, vector<int>(cols,1));

            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        // Set i th row to zero
                        for(int j = 0; j < cols; j++)
                            result[i][j] = 0;
                        
                        // Set jth col to zero
                        for(int i = 0; i < rows; i++)
                            result[i][j] = 0;
                    }
                }
            }

            return result;
        }

        // Approach 2
        // Without using an extra Matrix - Doing Modification Inplace
        // First Intutition - As we traverse the matrix if matrix[i][j] == 0 set ith row and jth col = 0
        // But since we are modifying the original matrix we wil losse information
        // for e.g matrix[0][1] = 0 Row 0 = [1,0,1,1,0,1,0]
        // Set 0th row = 0 and 1th col = 0
        // Updated Row 0 = [0,0,0,0,0,0,0]
        // We lost that cols no. 4 and 6 were zeros
        // How can we avoid this lost ?
        // Store the rows and col no's which have zeros  - In a array

        // T.C - O(N*M)
        // S.C - O(N + M)

        void set_zero1(vector<vector<int>> &matrix)
        {
            int rows = matrix.size(), cols = matrix[0].size();
            vector<bool> zero_rows(rows,false);
            vector<bool> zero_cols(cols,false);
            // rows[i] = true - ith row contain zero - Set ith row to zero

            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j< cols; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        zero_rows[i] = true;
                        zero_cols[j] = true; 
                    }
                }
            }

            // Now set the rows to zeros 
            for(int i = 0; i < rows; i++)
                if(zero_rows[i])
                    for(int j = 0; j < cols; j++)
                        matrix[i][j] = 0;

            // Now set the cols to zeros
            for(int j = 0; j < cols; j++)
                if(zero_cols[j])
                    for(int i = 0; i < rows; i++)
                        matrix[i][j] = 0;
            
        }

        // Approach 3
        // Is there any way to store the same information (zero_rows and zero_cols) without any extra space
        // zeroth row will store - cols which contain zero 
        // if matrix[0][j] = 0 , jth col contain zeros
        // Similarly zeroth col will store - rows which contain zero
        // IF matrix[i][0] = 0 , ith row contain zeros

        // T.C - O(N*M)
        // S.C - O(1)

        void set_zero2(vector<vector<int>> &matrix)
        {
            int rows = matrix.size() , cols = matrix[0].size();
            int zeroth_row = 1, zeroth_col = 1;
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0;  j< cols; j++)
                {
                    if(matrix[i][j] == 0 )
                    {
                        if(i == 0) zeroth_row = 0;
                        if(j == 0) zeroth_col = 0;
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            // Now set rows and cols to zero
            // rows[0][0] = 0 - means either  0th row or 0th col contain zeros or both 0th row anc 0th col contains zeros
            // How we will find which one of them is true
            // Store the what was present intially at cell[0][0]

            // set Rows to zeros starting from Row1 - Because we are using Row 0 to store zero rows
            for(int i = 1; i < rows; i++)
            {
                for(int j = 1; j < cols; j++)
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) // ith row or jth col contains zero
                        matrix[i][j] = 0;
            }
            
            if(zeroth_row == 0)
                for(int j = 0; j < cols; j++)
                    matrix[0][j] = 0;
            
            if(zeroth_col == 0)
                for(int i = 0; i < cols; i++)
                    matrix[0][i] = 0;
        }

        void display(vector<vector<int>> &matrix)
        {
            for(vector<int> &rows : matrix)
            {
                for(int &num : rows)
                    cout << num << " ";
                cout << endl;
            }
            cout << endl;
        }

};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,0,1}, {1,1,1}, {1,1,0}};
    auto ans = s.set_zero(matrix);
    s.display(ans);
    
    // s.set_zero1(matrix);
    // s.display(matrix);

    s.set_zero2(matrix);
    s.display(matrix);

}