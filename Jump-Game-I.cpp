// https://leetcode.com/problems/jump-game/description/

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(i > maxIndex)
                return false;

            maxIndex = max(maxIndex, i+nums[i]);
        }
        
        return true;
    }
};
