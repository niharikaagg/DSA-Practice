// https://leetcode.com/problems/missing-number/description/

/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int trueSum=0, expectedSum=0;
        for(int i=0; i<nums.size(); i++)
            trueSum+=nums[i];

        for(int i=0; i<=nums.size(); i++)
            expectedSum+=i;

        return (expectedSum-trueSum);


        
        // vector <int> isPresent(nums.size()+1, 0);
        // for(int i=0; i<nums.size(); i++)
        // {
        //     isPresent[nums[i]] = 1;
        // }

        // for(int i=0; i<isPresent.size(); i++)
        // {
        //     if(isPresent[i]==0)
        //     return i;
        // }
        // return -1;
    }
};
