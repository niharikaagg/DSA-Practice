// https://leetcode.com/problems/valid-anagram/description/

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<int> count(26, 0);

        for(int i=0; i<s.length(); i++)
            count[s[i] - 'a']++;

        for(int i=0; i<t.length(); i++)
            count[t[i] - 'a']--;

        for(int i=0; i<count.size(); i++)
        {
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};
