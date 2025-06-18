// https://leetcode.com/problems/house-robber/description/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/



// Memoization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            int nonPick = dp[i-1];

            int pick = nums[i];
            if(i > 1)
                pick += dp[i-2];

            dp[i] = max(pick, nonPick);
        }

        return dp[n-1];
    }
};

// Tabulation

class Solution {
public:
    int func(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i == 0)
            return nums[0];

        if(dp[i]!= -1)
            return dp[i];

        int pick = nums[i], nonPick;

        nonPick = func(i-1, nums, dp);

        if(i>1)
            pick = func(i-2, nums, dp) + nums[i];

        return dp[i] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int amount = func(n-1, nums, dp);
        return amount;
    }
};

// Space Optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int prev1 = nums[0], prev2 = 0;

        for(int i=1; i<nums.size(); i++)
        {
            int nonPick = prev1;

            int pick = nums[i];
            if(i > 1)
                pick += prev2;

            int amount = max(pick, nonPick);

            prev2 = prev1;
            prev1 = amount;
        }

        return prev1;
    }
};
