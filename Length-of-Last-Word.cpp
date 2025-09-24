// https://leetcode.com/problems/length-of-last-word/

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/



class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;

        while(s[i] == ' ')
            i--;

        int length = 0;
        while(i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }

        return length;
    }
};
