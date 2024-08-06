// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/



class Solution {
public:
    bool check(vector<int>& nums) {

        int count=0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
                count++;
        }
        if(nums[nums.size()-1]>nums[0])
            count++;

        if(count<=1)
            return true;
        return false;



        // int min = INT_MAX;
        // int pos = -1;

        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]<min)
        //     {
        //         min = nums[i];
        //         pos = i;
        //     }
        // }

        // int i=nums.size()-1;
        // if(pos==0)
        // {
        //     while(nums[i]==min)
        //     {
        //         i--;
        //         if(i==-1)
        //             break;
        //     }
        // }

        // if(i!=nums.size()-1)
        //     pos=i+1;

        // int next;
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     if(pos==nums.size()-1)
        //         next=0;
        //     else
        //         next = pos+1;

        //     if(nums[pos]>nums[next])
        //         return false;

        //     if(pos==nums.size()-1)
        //         pos=0;
        //     else
        //         pos++;
        // }
        // return true;
    }
};
