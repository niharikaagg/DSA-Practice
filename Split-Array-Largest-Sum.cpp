// https://leetcode.com/problems/split-array-largest-sum/

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
*/



class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k, int maxSum)
    {
        int subarrays = 1, sum = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(sum + nums[i] > maxSum)
            {
                subarrays++;
                sum = nums[i];
            }

            else
                sum += nums[i];
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(numberOfSubarrays(nums, k, mid) <= k)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return s;
    }
};
