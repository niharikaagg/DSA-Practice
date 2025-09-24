// https://leetcode.com/problems/contains-duplicate-ii

/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(nums[i]) && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i;
        }

        return false;
    }
};
