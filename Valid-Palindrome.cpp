// https://leetcode.com/problems/valid-palindrome/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/



// Optimized using 2 pointers - no extra space
class Solution {
public:
    bool isalnum(char c)    // also an in-built function in <cctype> library
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;

        while(i < j)
        {
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};

// Uses extra space
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0; i<s.length(); i++)
        {
            char c = s[i];

            if(c >= 'a' && c <= 'z')
                temp.push_back(c);
            else if(c >= 'A' && c <= 'Z')
                temp.push_back(c+32);
            else if(c >= '0' && c <= '9')
                temp.push_back(c);
        }

        string rev = temp;
        reverse(temp.begin(), temp.end());
        return temp == rev;
    }
};
