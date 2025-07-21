// https://leetcode.com/problems/longest-palindromic-subsequence/

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/



// Memoization

class Solution {
public:
    int func(int i, int j,  vector<vector<int>> &dp, string &s, string &copy)
    {
        if(i<0 || j<0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == copy[j])
            return dp[i][j] = 1 + func(i-1, j-1, dp, s, copy);

        else
            return dp[i][j] = 0 + max(func(i-1, j, dp, s, copy), func(i, j-1, dp, s, copy));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();

        string copy = s;
        reverse(copy.begin(), copy.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return func(n-1, n-1, dp, s, copy);
    }
};

// Tabulation

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        string copy = s;
        reverse(copy.begin(), copy.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == copy[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};
