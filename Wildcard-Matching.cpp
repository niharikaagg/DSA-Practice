// https://leetcode.com/problems/wildcard-matching/

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;    // both strings exhausted

        // if pattern is exhausted
        for(int i=1; i<=m; i++)
            dp[i][0] = false;

        // if string is exhausted
        for(int j=1; j<=n; j++)
        {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                else
                    dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};
