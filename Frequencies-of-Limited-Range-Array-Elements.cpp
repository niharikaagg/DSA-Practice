// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

/*
You are given an array arr[] containing n positive integers. These integers can be from 1 to p, and some numbers may be repeated or absent. Your task is to count the frequency of all numbers that lie in the range 1 to n.
Do modify the array in-place changes in arr[], such that arr[i] = frequency(i) and assume 1-based indexing.

Note: The elements greater than n in the array can be ignored for counting.
*/



class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int count[N] = {0};
        for(int i=0; i<N; i++)
        {
            if (arr[i] > N)
                continue;
            count[arr[i]-1]++;
        }
        for(int i=0; i<N; i++)
            arr[i] = count[i];
    }
};
