// https://leetcode.com/problems/group-anagrams/

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& keys : mp)
            result.push_back(keys.second);

        return result;
    }
};
