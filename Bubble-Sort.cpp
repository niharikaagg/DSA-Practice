// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

/*
Given an Integer N and a list arr. Sort the array using bubble sort algorithm.
*/



class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        
        for(int i=n-1; i>0; i--)
        {
            int swapped = 0;
            
            for(int j=0; j<i; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                    swapped = 1;
                }
            }
            
            if(swapped == 0)
                break;
        }
    }
};
