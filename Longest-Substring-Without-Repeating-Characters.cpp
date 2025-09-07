// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string s, find the length of the longest substring without duplicate characters.
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> characters(256, -1);
        int left=0, right=0, len=0;

        while(right < s.length())
        {
            // if already exists in answer string
            if(characters[s[right]] != -1)
                left = max(left, characters[s[right]]+1); // max of current position and position next to where the current character appears earlier

            characters[s[right]] = right;
            len = max(len, right-left+1);
            right++;
        }

        return len;
    }
};
