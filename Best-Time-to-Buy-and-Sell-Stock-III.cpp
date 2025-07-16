// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/



// **** capacity = number of transactions left available ****

// Memoization

class Solution {
public:
    int func(int i, int n, int buy, int capacity, vector<vector<vector<int>>> &dp, vector<int> &prices)
    {
        if(capacity == 0)
            return 0;
        if(i == n)
            return 0;

        if(dp[i][buy][capacity] != -1)
            return dp[i][buy][capacity];

        int profit = 0;

        // max of pick or not pick for buy as well as sell
        if(buy)     // can buy (buy = 1)
            profit = max((-prices[i] + func(i+1, n, 0, capacity, dp, prices)), (0 + func(i+1, n, 1, capacity, dp, prices)));
        else        // can sell (buy = 0)
            profit = max((prices[i] + func(i+1, n, 1, capacity-1, dp, prices)), (0 + func(i+1, n, 0, capacity, dp, prices)));

        return dp[i][buy][capacity] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        // capacity = 2 initially, reduces with every sell
        return func(0, n, 1, 2, dp, prices);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        // // base case: capacity = 0
        // for(int i=0; i<n; i++)
        //     for(int buy=0; buy<=1; buy++)
        //         dp[i][buy][0] = 0;

        // // base case: i = n
        // for(int buy=0; buy<=1; buy++)
        //     for(int capacity=0; capacity<=2; capacity++)
        //         dp[n][buy][capacity] = 0;

        // we can remove the base cases and initialize dp with 0 since the base cases are returning 0
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        int profit = 0;

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int capacity=1; capacity<=2; capacity++)
                {
                    if(buy)
                        profit = max((-prices[i] + dp[i+1][0][capacity]), (0 + dp[i+1][1][capacity]));
                    else
                        profit = max((prices[i] + dp[i+1][1][capacity-1]), (0 + dp[i+1][0][capacity]));

                    dp[i][buy][capacity] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};

