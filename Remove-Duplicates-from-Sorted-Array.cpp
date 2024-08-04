// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
    int i=0, j=1, count=1;
    while(i<nums.size() && j<nums.size())
    {
        if(nums[i] == nums[j])
            j++;
        else
        {
            nums[i+1] = nums[j];
            count++;
            i++;
        }
    }
    return count;


    // if (nums.size() == 1)
    //     return 1;

    // int count=0;
    // int temp, i, j;

    // for(i=0; i<nums.size()-1; i++)
    // {
    //     if(nums[i]==nums[i+1])
    //     {
    //         temp=nums[i+1];
    //         for(j=i+1; j<nums.size()-1; j++)
    //         {
    //             nums[j]=nums[j+1];
    //         }
    //         nums[j]=temp;
    //         if(i==0)
    //             i=-1;
    //         else
    //             i--;
    //     }
    //     else
    //     {
    //         count++;
    //         if(nums[i]>nums[i+1])
    //             break;
    //     }
    // }
    // return count;



    //     vector <int> ans;
    //     int i=0;
    //     for(i=0; i<nums.size()-1; i++)
    //     {
    //         if(nums[i+1] == nums[i])
    //         continue;
    //         else
    //         ans.push_back(nums[i]);
    //     }
    //     ans.push_back(nums[i]);
    //     for(i=0; i<ans.size(); i++)
    //     {
    //         nums[i] = ans[i];
    //     }
    //     int k = ans.size();
    //     return k;
    }
};
