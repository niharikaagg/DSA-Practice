// https://leetcode.com/problems/longest-common-subsequence/

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/



// Memoization

class Solution {
public:
    int func(int i, int j,  vector<vector<int>> &dp, string &text1, string &text2)
    {
        if(i<0 || j<0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + func(i-1, j-1, dp, text1, text2);

        else
            return dp[i][j] = 0 + max(func(i-1, j, dp, text1, text2), func(i, j-1, dp, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m-1, n-1, dp, text1, text2);
    }
};

// Tabulation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // shifting of indexes one step to the right since the base case returns on -ve index, which is not possible in tabulation
        // now 0 means -1 and n+1 means n
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<=m; i++)
            dp[i][0] = 0;

        for(int j=0; j<=n; j++)
            dp[0][j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};
