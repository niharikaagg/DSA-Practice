// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
*/



class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map <int, int> prefixSum;
        int sum=0, maxLen=0;
        
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            
            if(sum == k)
                maxLen = max(maxLen, i+1);
                
            int rem = sum - k;
            
            if(prefixSum.find(rem) != prefixSum.end())
            {
                int len = i - prefixSum[rem];
                maxLen = max(maxLen, len);
            }
            
            if(prefixSum.find(sum) == prefixSum.end())
                prefixSum[sum] = i;
        }
        
        return maxLen;
    }
};
