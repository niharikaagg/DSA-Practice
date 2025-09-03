// https://leetcode.com/problems/find-a-peak-element-ii/

/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/



class Solution {
public:
    int maxElementInRow(vector<vector<int>>& mat, int col)
    {
        int maxElement = INT_MIN;
        int row = -1;

        for(int i=0; i<mat.size(); i++)
        {
            if(mat[i][col] > maxElement)
            {
                maxElement = mat[i][col];
                row = i;
            }
        }

        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int s = 0, e = m-1;

        while(s <= e)
        {
            int col = s + (e-s)/2;

            int row = maxElementInRow(mat, col);

            int leftElement = col-1 >= 0 ? mat[row][col-1] : -1;
            int rightElement = col+1 < m ? mat[row][col+1] : -1;

            if(mat[row][col] > leftElement && mat[row][col] > rightElement)
                return {row, col};
            else if(leftElement > mat[row][col])
                e = col - 1;
            else
                s = col + 1;
        }

        return {-1, -1};
    }
};
