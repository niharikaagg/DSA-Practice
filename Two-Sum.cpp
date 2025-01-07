// https://leetcode.com/problems/two-sum/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> temp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
            temp.push_back(nums[i]);

        sort(temp.begin(), temp.end());

        int i=0, j=temp.size()-1;

        while(i<j)
        {
            if(temp[i]+temp[j] == target)
            {
                for(int k=0; k<nums.size(); k++)
                {
                    if(nums[k] == temp[i])
                    {
                        ans.push_back(k);
                        continue;
                    }
                    if(nums[k] == temp[j])
                        ans.push_back(k);
                }

                return ans;
            }

            else if(temp[i]+temp[j] > target)
                j--;

            else if(temp[i]+temp[j] < target)
                i++;
        }

        return ans;
    }
};
