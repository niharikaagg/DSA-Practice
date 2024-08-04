// https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest

/*
Given an array arr, return the second largest distinct element from an array. If the second largest element doesn't exist then return -1.
*/



class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // int max = INT_MIN;
        // for(int i=0; i<arr.size(); i++)
        // {
        //     if(arr[i] > max)
        //         max = arr[i];
        // }
        // int max2 = INT_MIN;
        // for(int i=0; i<arr.size(); i++)
        // {
        //     if(arr[i] > max2 && arr[i] < max)
        //         max2 = arr[i];
        // }
        
        // if(max2 == max)
        //     return -1;
        // return max2;
        
        int max=arr[0], max2=INT_MIN;   // second element can be largest
        
        if(arr.size() < 2)
            return -1;
        
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]>max)
            {
                max2=max;
                max=arr[i];
            }
            else if(arr[i]>max2 && arr[i]!=max)   // largest element can have duplicate values
            {
                max2=arr[i];
            }
        }
        if(max==max2)
            return -1;
        return max2;
    }
};
