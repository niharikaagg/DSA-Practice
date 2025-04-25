// https://www.geeksforgeeks.org/problems/geek-jump/1

/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.
*/



// Memoization

class Solution {
  public:
    int func(int index, vector<int> &height, vector<int> &dp)
    {
        if(index == 0)
            return 0;
            
        if(dp[index] != -1)
            return dp[index];
            
        int jump1, jump2 = INT_MAX;
        
        jump1 = func(index-1, height, dp) + abs(height[index] - height[index-1]);
        
        if(index > 1)
            jump2 = func(index-2, height, dp) + abs(height[index] - height[index-2]);
            
        return dp[index] = min(jump1, jump2);
    }
  
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);
        
        int cost = func(height.size()-1, height, dp);
        
        return cost;
    }
};


// Tabulation

class Solution {
  public:
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);

        dp[0] = 0;
        int jump1, jump2 = INT_MAX;
        
        for(int i=1; i<height.size(); i++)
        {
            jump1 = dp[i-1] + abs(height[i] - height[i-1]);
            
            if(i > 1)
                jump2 = dp[i-2] + abs(height[i] - height[i-2]);
                
            
            dp[i] = min(jump1, jump2);
        }
        
        return dp[height.size()-1];
    }
};


// Space Optimization

class Solution {
  public:
    int minCost(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        
        int prev1 = 0, prev2 = 0;
        int jump2 = INT_MAX, jump1, minCost = 0;
        
        for(int i=1; i<height.size(); i++)
        {
            jump1 = prev1 + abs(height[i] - height[i-1]);
            
            if(i > 1)
                jump2 = prev2 + abs(height[i] - height[i-2]);
                
            minCost = min(jump1, jump2);
            
            prev2 = prev1;
            prev1 = minCost;
        }
        
        return minCost;
    }
};
