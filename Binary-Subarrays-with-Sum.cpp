// https://leetcode.com/problems/binary-subarrays-with-sum/description/

/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
*/



class Solution {
public:
    int atMostSum(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;
        
        int l = 0, r = 0, count = 0, sum = 0;

        while(r < nums.size())
        {
            sum += nums[r];

            while(sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            count += r-l+1;

            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostSum(nums, goal) - atMostSum(nums, goal-1);
    }
};
