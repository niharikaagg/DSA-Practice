// https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

/*
The task is to complete the insert() function which is used to implement Insertion Sort.
*/



class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1; i<n; i++)
        {
            insert(arr, i);
        }
    }
};
