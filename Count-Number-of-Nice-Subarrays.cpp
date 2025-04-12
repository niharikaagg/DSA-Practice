// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/



class Solution {
public:
    int atMostOdd(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, odd = 0;

        while(r < nums.size())
        {
            if(nums[r]%2 != 0)
                odd++;

            while(odd > k)
            {
                if(nums[l]%2 != 0)
                    odd--;

                l++;
            }

            count += r-l+1;

            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostOdd(nums, k) - atMostOdd(nums, k-1);
    }
};
