// https://leetcode.com/problems/reverse-words-in-a-string/

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/



class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        for(int i=0; i<n; i++)
        {
            while(i<n && s[i] == ' ')
                i++;
            
            // to avoid blank space in beginning from trailing blank spaces in given string
            if(i >= n)
                break;
            
            int j = i+1;
            while(j<n && s[j] != ' ')
                j++;

            string word = s.substr(i, j-i);    // (startIndex, length)
            
            // to avoid trailing blank spaces caused due to first word
            if(ans == "")
                ans = word;
            else
                ans = word + " " + ans;

            i = j;
        }

        return ans;
    }
};
