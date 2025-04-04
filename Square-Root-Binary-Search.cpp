// https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

/*
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number
*/



class Solution {
  public:
    int floorSqrt(int n) {
        int s=1, e=n, ans=-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(mid*mid <= n)
            {
                ans = mid;
                s = mid+1;
            }
            
            else
            {
                e = mid-1;
            }
        }
        
        return ans;
    }
};
