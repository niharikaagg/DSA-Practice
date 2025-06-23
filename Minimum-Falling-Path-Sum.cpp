// https://leetcode.com/problems/minimum-falling-path-sum/

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/



// Memoization

/*
********************* THIS WILL GIVE TLE IN SOME CASES *********************
*/

class Solution {
public:
    int func(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix)
    {
        if(j<0 || j>=n)
            return 1e9;    // return large value for out of bound

        if(i==0)
            return matrix[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + func(i-1, j, n, dp, matrix);
        int leftUp = matrix[i][j] + func(i-1, j-1, n, dp, matrix);
        int rightUp = matrix[i][j] + func(i-1, j+1, n, dp, matrix);

        return dp[i][j] = min(up, min(leftUp, rightUp));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int mini = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0; j<n; j++)
        {
            int sum = func(n-1, j, n, dp, matrix);

            mini = min(mini, sum);
        }

        return mini;
    }
};

// Tabulation

/*
********************* THIS WILL NOT GIVE TLE IN ANY CASE *********************
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0; j<n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];

                int leftUp = matrix[i][j];
                if(j>0)
                    leftUp += dp[i-1][j-1];
                else
                    leftUp += 1e9;  // large value for out of bound

                int rightUp = matrix[i][j];
                if(j<n-1)
                    rightUp += dp[i-1][j+1];
                else
                    rightUp += 1e9; // large value for out of bound

                dp[i][j] = min(up, min(leftUp, rightUp));
            }
        }

        int mini = INT_MAX;

        for(int j=0; j<n; j++)
            mini = min(mini, dp[n-1][j]);

        return mini;
    }
};
