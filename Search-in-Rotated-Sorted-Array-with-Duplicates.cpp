// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid] == target)
                return true;

            // nums[low] = nums[mid] = nums[high]
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }   // eliminate nums[low] and nums[high] from consideration

            // left sorted
            else if(nums[low] <= nums[mid])
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

        return false;
    }
};
