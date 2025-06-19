// https://leetcode.com/problems/house-robber-ii/description/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/



// Memoization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        if(n == 1)
            return nums[0];

        dp[0] = nums[0];

        for(int i=1; i<n-1; i++)
        {
            int nonPick = dp[i-1];

            int pick = nums[i];
            if(i > 1)
                pick += dp[i-2];

            dp[i] = max(pick, nonPick);
        }

        int ans1 = dp[n-2];

        dp.assign(n, -1);

        dp[1] = nums[1];

        for(int i=2; i<n; i++)
        {
            int nonPick = dp[i-1];

            int pick = nums[i];
            if(i > 2)
                pick += dp[i-2];

            dp[i] = max(pick, nonPick);
        }

        int ans2 = dp[n-1];

        return max(ans1, ans2);
    }
};

// Tabulation

class Solution {
public:
    int func(int i, vector<int> &arr, vector<int> &dp)
    {
        if(i == 0)
            return arr[0];

        if(dp[i] != -1)
            return dp[i];

        int pick = arr[i], nonPick;

        nonPick = func(i-1, arr, dp);

        if(i > 1)
            pick = func(i-2, arr, dp) + arr[i];

        return dp[i] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> arr1, arr2;
        vector<int> dp(n-1, -1);

        if(n == 1)
            return nums[0];

        for(int i=0; i<n; i++)
        {
            if(i < n-1)
                arr1.push_back(nums[i]);
            if(i != 0)
                arr2.push_back(nums[i]);
        }

        int ans1 = func(n-2, arr1, dp);
        dp.assign(n-1, -1);
        int ans2 = func(n-2, arr2, dp);

        return max(ans1, ans2);
    }
};
