// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

/*
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.
*/



class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int ans = 1, count = 1;
        int i = 1, j = 0;
        
        while(i < arr.size() && j < dep.size())
        {
            if(arr[i] > dep[j])
            {
                count--;
                j++;
            }
            
            else
            {
                count++;
                i++;
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};
