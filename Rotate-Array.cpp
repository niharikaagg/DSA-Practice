// https://leetcode.com/problems/rotate-array/description/

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/


class Solution {
public:

    void reverse(vector<int> &arr, int i, int j)
    {
        while(i<=j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        
        if(k>nums.size())
            k=k%nums.size();

        int i,j;

        i=0; j=nums.size()-k-1;
        reverse(nums, i, j);

        for(int p=0; p<nums.size(); p++)
            cout<<nums[p];

        i=nums.size()-k; j=nums.size()-1;
        reverse(nums, i, j);

        i=0; j=nums.size()-1;
        reverse(nums, i, j);



        // if(k>nums.size())
        //     k=k%nums.size();
        // vector<int> ans;
        // int i=nums.size()-k;

        // while(k)
        // {
        //     ans.push_back(nums[i]);
        //     i++;
        //     k--;
        // }
        
        // for(int j=0; j<nums.size(); j++)
        //     ans.push_back(nums[j]);
        
        // for(int j=0; j<nums.size(); j++)
        //     nums[j]=ans[j];
    }
};
