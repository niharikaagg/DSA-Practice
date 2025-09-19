// https://leetcode.com/problems/isomorphic-strings/description/

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/



// 1 map, but O(n^2) complexity

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, char> mp;

        for(int i=0; i<s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])
                    return false;
            }
            
            else
            {
                for(auto& it : mp)
                    if(it.second == t[i])
                        return false;

                mp[s[i]] = t[i];
            }
        }

        return true;
    }
};

// 2 maps, but O(n) complexity

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, char> mp1, mp2;

        for(int i=0; i<s.length(); i++)
        {
            if((mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i]) || (mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i]))
                return false;

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        return true;
    }
};
