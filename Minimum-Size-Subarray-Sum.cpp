// https://leetcode.com/problems/minimum-size-subarray-sum/

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, minLen = INT_MAX;

        while(r < nums.size())
        {
            sum += nums[r];

            while(sum >= target)
            {
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
