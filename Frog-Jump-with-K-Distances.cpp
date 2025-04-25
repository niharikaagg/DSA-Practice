// https://www.geeksforgeeks.org/problems/minimal-cost/1

/*
Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.
*/



// Memoization

class Solution {
  public:
    int func(int index, int k, vector<int> &arr, vector<int> &dp)
    {
        if(index == 0)
            return 0;
            
        if(dp[index] != -1)
            return dp[index];
            
        int cost = INT_MAX;
        
        for(int i=1; i<=k; i++)
        {
            if(index-i >= 0)
            {
                int jump = func(index-i, k, arr, dp) + abs(arr[index] - arr[index-i]);
                cost = min(cost, jump);
            }
        }
        
        return dp[index] = cost;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size(), -1);
        
        return func(arr.size()-1, k, arr, dp);
    }
};


// Tabulation

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
         vector<int> dp(arr.size(), -1);
      
        dp[0] = 0;
        
        for(int i=1; i<arr.size(); i++)
        {
            int cost = INT_MAX;
            
            for(int j=1; j<=k; j++)
            {
                if(i-j >= 0)
                {
                    int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                    cost = min(cost, jump);
                }
            }
            dp[i] = cost;
        }
        
        return dp[arr.size()-1];
    }
};
