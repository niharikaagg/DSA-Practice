// https://leetcode.com/problems/delete-operation-for-two-strings/

/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
*/



// Memoization

class Solution {
public:
int func(int i, int j,  vector<vector<int>> &dp, string &word1, string &word2)
    {
        if(i<0 || j<0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = 1 + func(i-1, j-1, dp, word1, word2);

        else
            return dp[i][j] = 0 + max(func(i-1, j, dp, word1, word2), func(i, j-1, dp, word1, word2));
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int same = func(m-1, n-1, dp, word1, word2);

        return m + n - 2*same;
    }
};

// Tabulation

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<=m; i++)
            dp[i][0] = 0;

        for(int j=0; j<=n; j++)
            dp[0][j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int same = dp[m][n];

        return m + n - 2*same;
    }
};
