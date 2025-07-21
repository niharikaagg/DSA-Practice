// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
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

    int minInsertions(string s) {
        int n = s.length();

        string copy = s;
        reverse(copy.begin(), copy.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int pal = func(n-1, n-1, dp, s, copy);

        return n - pal;
    }
};

// Tabulation

class Solution {
public:
    int minInsertions(string s) {
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

        int pal = dp[n][n];

        return n - pal;
    }
};
