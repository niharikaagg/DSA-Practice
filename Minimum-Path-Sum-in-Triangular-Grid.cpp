// https://leetcode.com/problems/triangle/description/

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/



// Memoization

class Solution {
public:
    int func(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &triangle)
    {
        if(i == n-1)
            return triangle[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int below = triangle[i][j] + func(i+1, j, n, dp, triangle);
        int belowSide = triangle[i][j] + func(i+1, j+1, n, dp, triangle);

        return dp[i][j] = min(below, belowSide);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return func(0, 0, n, dp, triangle);
    }
};

// Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0; j<n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int below = triangle[i][j] + dp[i+1][j];
                int belowSide = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(below, belowSide);
            }
        }

        return dp[0][0];
    }
};
