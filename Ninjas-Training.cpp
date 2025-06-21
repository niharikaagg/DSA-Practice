// https://www.geeksforgeeks.org/problems/geeks-training/1

/*
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .
*/



// Memoization

class Solution {
  public:
    int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if(day == 0)
        {
            int maxi = 0;
            
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            
            return maxi;
        }
        
        if(dp[day][last] != -1)
            return dp[day][last];
            
        int maxi = 0;
        
        for(int task = 0; task < 3; task++)
        {
            if(task != last)
            {
                int point = points[day][task] + func(day-1, task, points, dp);
                maxi = max(maxi, point);
            }
        }
        
        return dp[day][last] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        return func(n-1, 3, arr, dp);    // 3 is for none previous task
    }
};

// Tabulation

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        // dp is dp[day][lastTask]
        // initialize dp for day 0 and all possible last tasks
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day=1; day<n; day++)
        {
            for(int last=0; last<4; last++)
            {
                dp[day][last] = 0;
                
                for(int task=0; task<3; task++)
                {
                    if(task != last)
                    {
                        int point = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(point, dp[day][last]);
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }
};

// Space Optimization

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<int> prev(4, -1);

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day=1; day<n; day++)
        {
            vector<int> temp(4, -1);
            
            for(int last=0; last<4; last++)
            {
                temp[last] = 0;
                
                for(int task=0; task<3; task++)
                {
                    if(task != last)
                    {
                        int point = arr[day][task] + prev[task];
                        temp[last] = max(point, temp[last]);
                    }
                }
            }
            prev = temp;
        }
        
        return prev[3];
    }
};
