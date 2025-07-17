// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/



// Memoization

class Solution {
public:
    int func(int i, int n, int buy, vector<vector<int>> &dp, vector<int> &prices)
    {
        if(i >= n)
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if(buy)
            profit = max((-prices[i] + func(i+1, n, 0, dp, prices)), (0 + func(i+1, n, 1, dp, prices)));
        else    // do i+2 on selling (you can buy on next to next day)
            profit = max((prices[i] + func(i+2, n, 1, dp, prices)), (0 + func(i+1, n, 0, dp, prices)));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return func(0, n, 1, dp, prices);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp array size is n+2
        vector<vector<int>> dp(n+2, vector<int> (2, -1));

        dp[n][0] = dp[n][1] = 0;
        dp[n+1][0] = dp[n+1][1] = 0;

        int profit = 0;

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)     // can buy (buy = 1)
                    profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
                else        // can sell (buy = 0)
                    profit = max((prices[i] + dp[i+2][1]), (0 + dp[i+1][0]));

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
