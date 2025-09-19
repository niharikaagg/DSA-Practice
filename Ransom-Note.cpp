// https://leetcode.com/problems/ransom-note/description/

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(int i=0; i<magazine.length(); i++)
            mp[magazine[i]]++;

        for(int i=0; i<ransomNote.length(); i++)
        {
            if(mp.find(ransomNote[i])==mp.end() || mp[ransomNote[i]]==0)
                return false;
            mp[ransomNote[i]]--;
        }

        return true;
    }
};
