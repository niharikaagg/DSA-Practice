// https://leetcode.com/problems/max-consecutive-ones-iii/

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, zeroes=0, len=0;

        while(r < nums.size())
        {
            if(nums[r] == 0)
                zeroes++;

            if(zeroes > k)
            {
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }

            if(zeroes <= k)
                len = max(len, r-l+1);

            r++;
        }

        return len;
    }
};
