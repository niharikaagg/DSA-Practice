// https://leetcode.com/problems/unique-paths-ii/description/

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/



// Memoization

class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        if(i<0 || j<0)
            return 0;
        
        if(grid[i][j] == 1)
            return 0;

        if(i==0 && j==0)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = func(i-1, j, dp, grid);
        int left = func(i, j-1, dp, grid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m-1, n-1, dp, obstacleGrid);
    }
};

// Tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if(i==0 && j==0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(i>0)
                    up = dp[i-1][j];
                
                if(j>0)
                    left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};
