// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

/*
Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.
*/



class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector <int> leader;
        int max = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i]>=max)
            {
                leader.push_back(arr[i]);
                max = arr[i];
            }
        }
        
        vector<int> ans;
        for(int i=leader.size()-1; i>=0; i--)
        {
            ans.push_back(leader[i]);
        }
        return ans;
    }
};
