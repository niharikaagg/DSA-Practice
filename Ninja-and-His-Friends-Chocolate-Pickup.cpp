// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

/*
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/



// Memoization

class Solution {
  public:
    int func(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)
            return -1e9;    // small number for out of bounds
            
        if(i == n-1)
        {
            if(j1 == j2)
                return dp[i][j1][j2] = grid[i][j1];
            else
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
            
        int maxi = INT_MIN;
        
        for(int d1=-1; d1<=1; d1++)
        {
            for(int d2=-1; d2<=1; d2++)
            {
                int ans;
                
                if(j1 == j2)
                    ans = grid[i][j1] + func(i+1, j1+d1, j2+d2, n, m, dp, grid);
                else
                    ans = grid[i][j1] + grid[i][j2] + func(i+1, j1+d1, j2+d2, n, m, dp, grid);
                    
                maxi = max(maxi, ans);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return func(0, 0, m-1, n, m, dp, grid);
    }
};

// Tabulation

class Solution {
  public:
    int func(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)
            return -1e9;    // small number for out of bounds
            
        if(i == n-1)
        {
            if(j1 == j2)
                return dp[i][j1][j2] = grid[i][j1];
            else
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
            
        int maxi = INT_MIN;
        
        for(int d1=-1; d1<=1; d1++)
        {
            for(int d2=-1; d2<=1; d2++)
            {
                int ans;
                
                if(j1 == j2)
                    ans = grid[i][j1] + func(i+1, j1+d1, j2+d2, n, m, dp, grid);
                else
                    ans = grid[i][j1] + grid[i][j2] + func(i+1, j1+d1, j2+d2, n, m, dp, grid);
                    
                maxi = max(maxi, ans);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        for(int j1=0; j1<m; j1++)
        {
            for(int j2=0; j2<m; j2++)
            {
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j1=0; j1<m; j1++)
            {
                for(int j2=0; j2<m; j2++)
                {
                    int maxi = INT_MIN;
                    
                    for(int d1=-1; d1<=1; d1++)
                    {
                        for(int d2=-1; d2<=1; d2++)
                        {
                            int ans;
                            
                            if(j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];
                                
                            if(j1+d1<0 || j1+d1>=m || j2+d2<0 || j2+d2>=m)
                                ans += -1e9;
                            else
                                ans += dp[i+1][j1+d1][j2+d2];
                                
                            maxi = max(maxi, ans);
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};
