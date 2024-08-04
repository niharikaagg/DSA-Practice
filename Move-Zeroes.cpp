// https://leetcode.com/problems/move-zeroes/description/

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size()<=1)
            return;

        int i=0, j=1;

        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]!=0)
                i++;
            else if(nums[i]==0 && nums[j]!=0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        
        
        // int i,j,k=nums.size()-1;
        // for(i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]!=0)
        //     continue;

        //     for(j=i; j<nums.size(); j++)
        //     {
        //         if(nums[j]!=0)
        //         break;
        //     }
        //     if(j==nums.size())
        //     return;

        //     for(j=i+1; j<nums.size();j++)
        //     {
        //         nums[j-1] = nums[j];
        //     }
        //     nums[k]=0;
        //     k--;
        //     i--;
        // }
    }
};
