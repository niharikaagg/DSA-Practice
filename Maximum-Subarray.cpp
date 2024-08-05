// https://leetcode.com/problems/maximum-subarray/description/

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Kadane's Algorithmt
        
        int sum=0;
        int maxSum=INT_MIN;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};
