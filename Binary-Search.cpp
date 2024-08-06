// https://leetcode.com/problems/binary-search/description/

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(nums[mid]==target)
                return mid;

            else if(nums[mid]>target)
                e=mid-1;

            else if(nums[mid]<target)
                s=mid+1;
        }
        return -1;
    }
};
