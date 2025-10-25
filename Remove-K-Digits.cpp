// https://leetcode.com/problems/remove-k-digits/

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/



class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string st;

        if(k == n)
            return "0";

        for(int i=0; i<num.length(); i++)
        {
            while(!st.empty() && k > 0 && st.back() > num[i])
            {
                st.pop_back();
                k--;
            }

            st.push_back(num[i]);
        }

        while(k > 0)   // larger digits left at end
        {
            st.pop_back();
            k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0')    // remove trailing zeroes
            i++;
        
        string res = st.substr(i);

        return res.empty() ? "0" : res;

    }
};
