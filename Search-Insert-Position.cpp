// https://leetcode.com/problems/search-insert-position/description/

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<e)
        {
            mid=s+(e-s)/2;

            if(target == nums[mid])
            return mid;
            
            else if(target < nums[mid])
            e=mid-1;

            else if(target > nums[mid])
            s=mid+1;
        }

        if(target > nums[s])
        return s+1;
        else
        return s;
    }
};
