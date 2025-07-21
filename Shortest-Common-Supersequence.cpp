// https://leetcode.com/problems/shortest-common-supersequence/

/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
*/



// No memoization method

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<=m; i++)
            dp[i][0] = 0;

        for(int j=0; j<=n; j++)
            dp[0][j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string ans = "";

        int i = m, j = n;

        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }

            else if(dp[i-1][j] > dp[i][j-1])
            {
                ans += str1[i-1];
                i--;
            }

            else
            {
                ans += str2[j-1];
                j--;
            }
        }

        while(i > 0)
        {
            ans += str1[i-1];
            i--;
        }

        while(j > 0)
        {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
