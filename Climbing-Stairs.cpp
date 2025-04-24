// https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/



class Solution {
public:
    int climbStairs(int n) {
        // This problem is just like fibonacci
        // '1 step' is added to all possible ways of (n-1), and '2 steps' are added to all possible ways of (n-2)
        // Total ways for n will be ways(n-1) + ways(n-2)

        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];


        // if(n == 0)
        //     return 1;

        // if(n == 1)
        //     return 1;

        // int prev2 = 1, prev1 = 1, curr;

        // for(int i=2; i<=n; i++)
        // {
        //     curr = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = curr;
        // }

        // return curr;
    }
};
