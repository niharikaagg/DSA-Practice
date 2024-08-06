// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], max_profit=0;
        for(int i=0; i<prices.size(); i++)
        {
            int profit = prices[i]-min;
            if(profit>max_profit)
                max_profit=profit;
            if(prices[i]<min)
                min=prices[i];
        }
        return max_profit;
    }
};
