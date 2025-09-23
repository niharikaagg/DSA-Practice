// https://leetcode.com/problems/longest-common-prefix/

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for(int i=0; i<strs[0].size(); i++)
        {
            char c = strs[0][i];

            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j].size() < i || strs[j][i] != c)
                    return res;

            }

            res.push_back(c);
        }

        return res;
    }
};
