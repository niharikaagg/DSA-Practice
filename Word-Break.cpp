// https://leetcode.com/problems/word-break/

/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<wordDict.size(); i++)
            maxLen = max(maxLen, (int)wordDict[i].length());

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++)
        {
            for(int j=i-1; j>=max(0, i-maxLen); j--)
            {
                if(dp[j] && dict.count(s.substr(j, i-j)))
                    dp[i] = true;
            }
        }

        return dp[n];
    }
};
