/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place? 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // Approach 1
        // Rotate Matrix = Transpose of Matrix
        // This Approach will works even if Matrix is not a square matrix 
        // Using Extra Matrix

        // T.C - O(N*M), N = rows, M = cols
        // S.C - (N*M)
        vector<vector<int>> rotate_matrix(vector<vector<int>> &matrix)
        {
            int rows = matrix.size(), cols = matrix[0].size();
            vector<vector<int>> rotated_matrix(rows, vector<int>(cols));

            for(int i = 0; i< rows; i++)
                for(int j = 0; j < cols; j++)
                    rotated_matrix[j][i] = matrix[i][j];

            return rotated_matrix;
        }

        // Approach 2
        // Without using an extra Matrix - Inplace 
        // This Approach only works when given matrix is N*N (Square Matrix)

        // T.C - O(N*N)
        // S.C - O(1)

        void rotate_matrix_inplace(vector<vector<int>> &matrix)
        {
            for(int i = 0; i < matrix.size(); i++)
                for(int j = i+1; j < matrix.size(); j++)
                    swap(matrix[i][j],matrix[j][i]);
        }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans =  s.rotate_matrix(matrix);
    for(vector<int> &row : ans)
    {
        for(int &num : row)
            cout << num << " ";
        cout << endl;;
    }

    cout << endl;

    s.rotate_matrix_inplace(matrix);
    for(vector<int> &row : matrix)
    {
        for(int &num : row)
            cout << num<< " ";
        cout <<endl;
    }
    
        
}