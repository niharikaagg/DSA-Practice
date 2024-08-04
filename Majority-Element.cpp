// https://leetcode.com/problems/majority-element/description/

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Moore's Voting Algorithm
        int el, count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count==0)
                el=nums[i];

            if(nums[i]==el)
                count++;
            else
                count--;
        }

        return el;


        // if majority element doesn't necessarily exist

        // int total;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i]==el)
        //         total++;
        // }

        // if(total>nums.size()/2)
        //     return el;
        // else
        //     return -1;
    }
};
