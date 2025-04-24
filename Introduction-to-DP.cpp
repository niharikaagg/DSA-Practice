// https://www.geeksforgeeks.org/problems/introduction-to-dp/1

/*
Geek is learning data structures, and he recently learned about the top-down and bottom-up dynamic programming approaches. Geek is having trouble telling them apart from one another.

When given an integer n, where n is based on a 0-based index, find the nth Fibonacci number.

Every ith number in the series equals the sum of the (i-1)th and (i-2)th numbers, where the first and second numbers are specified as 0 and 1, respectively.

For the given issue, code both top-down and bottom-up approaches.

Note : As the answer might be large, return the final answer modulo 109 + 7
*/



lass Solution {
  public:
    vector<int> dp;
    int MOD = 1e9 + 7;
    
    long long int performTopDown(int n, vector<int> &dp)
    {
        if(n <= 1)
            return n;
            
        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = (performTopDown(n-1, dp) + performTopDown(n-2, dp)) % MOD;
    }
  
    long long int topDown(int n) {
        dp.assign(n+1, -1);
        return performTopDown(n, dp);
        
        // TC - O(N), SC - O(N)+O(N)
    }
    
    long long int bottomUp(int n) {
        // vector<int> fib(n+1, -1);
        
        // fib[0] = 0;
        // fib[1] = 1;
        
        // for(int i=2; i<=n; i++)
        //     fib[i] = (fib[i-1] + fib[i-2]) % MOD;
            
        // return fib[n];
        
        // TC - O(N), SC - O(N)
        
        
        
        
        if(n == 0)
            return 0;
            
        if(n == 1)
            return 1;
        
        long long int prev2 = 0, prev1 = 1, fib;
        
        for(int i=2; i<=n; i++)
        {
            fib = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = fib;
        }
        
        return fib;
        
        // TC = O(N), SC - O(1)
    }
};
