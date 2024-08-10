// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        
        int s=0, e=nums.size()-1, index=-1;

        while(s<=e)
        {
            int mid = s+(e-s)/2;

            if(nums[mid] == target)
            {
                index = mid;
                e = mid-1;
            }

            else if(nums[mid] < target)
                s = mid+1;

            else if(nums[mid] > target)
                e = mid-1;
        }

        if(index == -1)
            return {-1, -1};

        ans.push_back(index);
        s=index, e=nums.size()-1;

        while(s<=e)
        {
            int mid = s+(e-s)/2;

            if(nums[mid] == target)
            {
                index = mid;
                s = mid+1;
            }

            else if(nums[mid] < target)
                s = mid+1;

            else if(nums[mid] > target)
                e = mid-1;
        }

        ans.push_back(index);

        return ans;
    }
};
