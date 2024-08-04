// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

/*
Given an array arr, the task is to find the largest element in it.
*/



class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};
