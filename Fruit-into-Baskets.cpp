// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

/*
Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.
*/



class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int l=0, r=0, len=0;
        unordered_map<int, int> m;
        
        while(r < arr.size())
        {
            m[arr[r]]++;
            
            if(m.size() > 2)
            {
                while(m.size() > 2)
                {
                    m[arr[l]]--;
                    
                    if(m[arr[l]] == 0)
                        m.erase(arr[l]);
                        
                    l++;
                }
                
            }
            
            if(m.size() <= 2)
                len = max(len, r-l+1);
            
            r++;
        }
        
        return len;
    }
};
