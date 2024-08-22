// https://leetcode.com/problems/largest-odd-number-in-string/description/

/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
*/



class Solution {
public:
    string largestOddNumber(string num) {
        if(((int(num[num.length()-1]))-48) % 2 != 0)
            return num;

        int i = num.length()-1;

        while(i>=0 && ((int(num[i])-48) % 2 == 0))
            i--;

        if(i==-1)
            return "";

        return num.substr(0, i+1);    // returns substring substr(start, length)
    }
};
