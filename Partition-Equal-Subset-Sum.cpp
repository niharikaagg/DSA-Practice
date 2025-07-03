// https://leetcode.com/problems/partition-equal-subset-sum/

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/



// Memoization

class Solution {
public:
    bool func(int i, int half, vector<vector<int>> &dp, vector<int> &nums)
    {
        if(half == 0)
            return true;
            
        if(i == 0)
            return (nums[0] == half);
            
        if(dp[i][half] != -1)
            return dp[i][half];
            
        bool notPick = func(i-1, half, dp, nums);
        
        bool pick = false;
        if(nums[i] <= half)
            pick = func(i-1, half-nums[i], dp, nums);
            
        return dp[i][half] = pick||notPick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i=0; i<n; i++)
            sum += nums[i];

        if(sum%2 != 0)
            return false;

        int half = sum/2;

        vector<vector<int>> dp(n, vector<int>(half+1, -1));

        return func(n-1, half, dp, nums);
    }
};

// Tabulation

class Solution {
public:
    bool func(int i, int half, vector<vector<int>> &dp, vector<int> &nums)
    {
        if(half == 0)
            return true;
            
        if(i == 0)
            return (nums[0] == half);
            
        if(dp[i][half] != -1)
            return dp[i][half];
            
        bool notPick = func(i-1, half, dp, nums);
        
        bool pick = false;
        if(nums[i] <= half)
            pick = func(i-1, half-nums[i], dp, nums);
            
        return dp[i][half] = pick||notPick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i=0; i<n; i++)
            sum += nums[i];

        if(sum%2 != 0)
            return false;

        int half = sum/2;

        vector<vector<bool>> dp(n, vector<bool>(half+1, false));

        for(int i=0; i<n; i++)
            dp[i][0] = true;

        if(nums[0] <= half)
            dp[0][nums[0]] = true;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=half; j++)
            {
                bool notPick = dp[i-1][j];

                bool pick = false;
                if(nums[i] <= j)
                    pick = dp[i-1][j-nums[i]];

                dp[i][j] = pick || notPick;
            }
        }

        return dp[n-1][half];
    }
};
