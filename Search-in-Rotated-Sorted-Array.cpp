// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid] == target)
                return mid;

            // left sorted
            if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && nums[mid] >= target)    // target in this half
                    high = mid-1;   // eliminate other half
                else
                    low = mid+1;    // eliminate this half
            }

            // right sorted
            else
            {
                if(nums[high] >= target && nums[mid] <= target)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }

        return -1;
    }
};
