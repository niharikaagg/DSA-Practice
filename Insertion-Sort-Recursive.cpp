// https://www.geeksforgeeks.org/problems/insertion-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

/*
The task is to complete the insert() function which is used to implement Insertion Sort.
*/



class Solution
{
    public:
    void insertionSort(int arr[], int i, int n)
    {
        // Recursive
      
        if(i == n)
            return;
            
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1], arr[j]);
            j--;
        }
        
        inserstionSort(arr, i+1, n);
    }
};
