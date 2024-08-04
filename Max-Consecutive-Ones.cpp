// https://leetcode.com/problems/max-consecutive-ones/description/

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maxCount=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count++;
                if(count>maxCount)
                    maxCount=count;
            }
            else
                count=0;
        }
        return maxCount;
    }
};
