// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

/*
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 
*/



// Memoization

class Solution {
  public:
    bool func(int i, int sum, vector<vector<int>> &dp, vector<int> &arr)
    {
        if(sum == 0)
            return true;
            
        if(i == 0)
            return (arr[0] == sum);
            
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        bool notPick = func(i-1, sum, dp, arr);
        
        bool pick = false;
        if(arr[i] <= sum)
            pick = func(i-1, sum-arr[i], dp, arr);
            
        return dp[i][sum] = pick||notPick;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return func(n-1, sum, dp, arr);
    }
};

// Tabulation

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++)
            dp[i][0] = true;
            
        dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                bool notPick = dp[i-1][j];
        
                bool pick = false;
                if(arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];
                    
                dp[i][j] = pick||notPick;
            }
        }
        
        return dp[n-1][sum];
    }
};
