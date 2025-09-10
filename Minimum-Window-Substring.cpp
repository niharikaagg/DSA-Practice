// https://leetcode.com/problems/minimum-window-substring/

/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/



class Solution {
public:
    string minWindow(string s, string t) {
        if(s == "" || t == "")
            return "";

        int l=0, r=0, count=0, minLen=INT_MAX, startIndex=-1;
        vector<int> characters(256, 0);

        for(int i=0; i<t.length(); i++)
            characters[t[i]]++;

        while(r < s.length())
        {
            if(characters[s[r]] > 0)
                // count the characters from t in s
                count++;

            characters[s[r]]--;

            while(count == t.length())
            {
                if(r-l+1 < minLen)
                {
                    minLen = r-l+1;
                    startIndex = l;
                }

                characters[s[l]]++;
                if(characters[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
