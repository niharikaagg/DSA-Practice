// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
*/



// Memoization

class Solution {
public:
    int func(int i, int n, int buy, int fee, vector<vector<int>> &dp, vector<int> &prices)
    {
        if(i == n)
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if(buy)
            profit = max((-prices[i] + func(i+1, n, 0, fee, dp, prices)), (0 + func(i+1, n, 1, fee, dp, prices)));
        else    // minus the fee on selling
            profit = max((prices[i] + func(i+1, n, 1, fee, dp, prices) - fee), (0 + func(i+1, n, 0, fee, dp, prices)));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return func(0, n, 1, fee, dp, prices);
    }
};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        dp[n][0] = dp[n][1] = 0;

        int profit = 0;

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)
                    profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
                else    // minus transaction fee on selling
                    profit = max((prices[i] + dp[i+1][1] - fee), (0 + dp[i+1][0]));

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
