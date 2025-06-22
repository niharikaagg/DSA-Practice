// https://leetcode.com/problems/minimum-path-sum/

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/



// Memoization

class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        if(i==0 && j==0)
            return grid[i][j];

        if(i<0 || j<0)
            return INT_MAX; // if we go out of bound, choose a large value to avoid using this path as this will not be able to return minimum value

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = func(i-1, j, dp, grid);
        int left = func(i, j-1, dp, grid);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m-1, n-1, dp, grid);
    }
};

// Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = grid[i][j];

                if(i > 0)
                    up += dp[i-1][j];
                else
                    up += 1e9;  // a large value for out of bounds so it does not get picked up in minimum

                int left = grid[i][j];

                if(j > 0)
                    left += dp[i][j-1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};
