// https://www.geeksforgeeks.org/problems/aggressive-cows/1

/*
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
*/



class Solution {
  public:
    bool canPlace(vector<int> &stalls, int k, int dist)
    {
        int countCows = 1, lastCow = stalls[0];
        
        for(int i=1; i<stalls.size(); i++)
        {
            if(stalls[i] - lastCow >= dist)
            {
                countCows++;
                lastCow = stalls[i];
                
                if(countCows == k)
                    return true;
            }
        }
        
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        // range of possible distances
        int s = 1, e = stalls[n-1];
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(canPlace(stalls, k, mid))
                s = mid + 1;
            else
                e = mid - 1;
        }
        
        return e;
    }
};
