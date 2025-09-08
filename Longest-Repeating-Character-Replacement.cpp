// https://leetcode.com/problems/longest-repeating-character-replacement/

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/



class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, changes=0, len=0, maxFreq=0;
        vector<int> frequency(26, 0);

        while(r < s.length())
        {
            frequency[s[r] - 'A']++;
            maxFreq = max(maxFreq, frequency[s[r] - 'A']);
            changes = (r-l+1) - maxFreq;

            if(changes > k)
            {
                frequency[s[l] - 'A']--;
                l++;
            }

            len = max(len, r-l+1);
            r++;
        }

        return len;
    }
};
