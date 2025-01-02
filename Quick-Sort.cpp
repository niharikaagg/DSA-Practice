// https://www.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort

/*
Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. Given an array, arr[], with starting index low and ending index high, complete the functions partition() and quickSort(). Use the last element as the pivot so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.
*/



class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high)
        {
            int partIndex = partition(arr, low, high);
            quickSort(arr, low, partIndex-1);
            quickSort(arr, partIndex+1, high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i=low;
        int j=high;
        
        while(i<j)
        {
            while(arr[i]<=pivot && i<=high)
                i++;
                
            while(arr[j]>pivot && j>=low)
                j--;
                
            if(i<j)
                swap(arr[i], arr[j]);
        }
        
        swap(arr[j], arr[low]);
        
        return j;
    }
};
