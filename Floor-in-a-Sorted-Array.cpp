// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

/*
Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x
is defined as the largest element k in arr[] such that k is smaller than or equal to x.
Find the index of k(0-based indexing).
*/



class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        int s=0, e=n-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(v[mid]==x)
                return mid;
                
            else if(v[mid] > x)
                e = mid-1;
                
            else if(v[mid] < x)
                s = mid+1;
        }
        
        if(s>e)
            return s-1;
        else(v[s] > x)
            return -1;
        else
            return s;
    }
};
