// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

/*
Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.
*/



class Solution
{
    public:
    int select(int arr[], int i)
    {
        int max = INT_MIN;
        int index = -1;
        int j;
        
        for(j=i; j>=0; j--)
        {
            if(arr[j] > max)
            {
                max = arr[j];
                index = j;
            }
        }
        
        return index;
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i=n-1; i>=0; i--)
       {
           int maxIndex = select(arr, i);
           swap(arr[i], arr[maxIndex]);
       }
    }
};
