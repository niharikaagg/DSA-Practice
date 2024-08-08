// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.
*/



class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        
        vector<int> ans(2);
        
        int f=INT_MIN, c=INT_MAX;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]<=x && arr[i]>f)
                f = arr[i];
            
            if(arr[i]>=x && arr[i]<c)
                c = arr[i];
        }
        
        
        if(f==INT_MIN)
            ans[0] = -1;
        else
            ans[0] = f;
        if(c==INT_MAX)
            ans[1] = -1;
        else
            ans[1] = c;
        
            
        return ans;
    }
};
