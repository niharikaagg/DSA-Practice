// https://leetcode.com/problems/set-matrix-zeroes/

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // row[m] = {0} -> matrix[..][0]
        // col[n] = {0} -> matrix[0][..]

        int col0 = 1;   // to prevent overlapping

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    // mark for row
                    matrix[i][0] = 0;
                    
                    // mark for col
                    if(j == 0)
                        col0 = 0;
                    else
                        matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // for row 0
        if(matrix[0][0] == 0)
        {
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        }

        // for col 0
        if(col0 == 0)
        {
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        }
    }
};
