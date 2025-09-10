// https://leetcode.com/problems/subarrays-with-k-different-integers/

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/



class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int l=0, r=0, count=0;
        unordered_map<int, int> m;

        while(r < nums.size())
        {
            m[nums[r]]++;

            while(m.size() > k)
            {
                m[nums[l]]--;
                if(m[nums[l]] == 0)
                    m.erase(nums[l]);

                l++;
            }

            count += r-l+1;
            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return numberOfSubarrays(nums, k) - numberOfSubarrays(nums, k-1);
    }
};
