// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

/*
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.
*/



class Solution {
  public:
    int func(int mid, int m, int n)
    {
        /*
        to avoid overflow on large value of mid^n,
        return 0 if < m
        return 1 if == m
        return 2 if > m
        */
        
        long long ans = 1;
        
        for(int i=1; i<=n; i++)
        {
            ans = ans * mid;
            
            if(ans > m)
                return 2;
        }
        
        if(ans == m)
            return 1;
            
        return 0;
        
    }
  
    int nthRoot(int n, int m) {
        int s = 1, e = m, ans = -1;
        
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            
            int val = func(mid, m, n);
            
            if(val == 1)
                return mid;
            
            else if(val == 0)
                s = mid+1;
            
            else
                e = mid-1;
        }
        
        return ans;
    }
};
