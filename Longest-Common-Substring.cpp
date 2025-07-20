// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

/*
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.
*/



class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int maxLen = 0;

        for(int i=0; i<=m; i++)
            dp[i][0] = 0;

        for(int j=0; j<=n; j++)
            dp[0][j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLen = max(maxLen, dp[i][j]);
                }

                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLen;
    }
};
