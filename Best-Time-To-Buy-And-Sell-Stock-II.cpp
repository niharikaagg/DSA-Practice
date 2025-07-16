// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/



// Memoization

class Solution {
public:
    int func(int i, int n, int buy, vector<vector<int>> &dp, vector<int> &prices)
    {
        if(i == n)
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        // max of pick or not pick for buy as well as sell
        if(buy)     // can buy (buy = 1)
            profit = max((-prices[i] + func(i+1, n, 0, dp, prices)), (0 + func(i+1, n, 1, dp, prices)));
        else        // can sell (buy = 0)
            profit = max((prices[i] + func(i+1, n, 1, dp, prices)), (0 + func(i+1, n, 0, dp, prices)));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return func(0, n, 1, dp, prices);   // you can buy on day 0 since you own no stock yet
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        dp[n][0] = dp[n][1] = 0;

        int profit = 0;

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)     // can buy (buy = 1)
                    profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
                else        // can sell (buy = 0)
                    profit = max((prices[i] + dp[i+1][1]), (0 + dp[i+1][0]));

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
