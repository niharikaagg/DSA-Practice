// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=who-will-win

/*
Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.
*/



class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {

        // Linear Search
        for(int i=0; i<N; i++)
            if(arr[i]==K)
                return 1;
        return -1;
    }
};
