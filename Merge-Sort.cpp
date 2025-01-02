// https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort

/*
Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.
*/



class Solution {
  public:
  
    void merge(vector<int>& arr, int l, int mid, int r)
    {
        int left=l, right=mid+1, i=0;
        int temp[r-l+1];
        
        while(left<=mid && right<=r)
        {
            if(arr[left] <= arr[right])
            {
                temp[i++] = arr[left];
                left++;
            }
            
            else
            {
                temp[i++] = arr[right];
                right++;
            }
        }
        
        while(left<=mid)
        {
            temp[i++] = arr[left];
            left++;
        }
        
        while(right<=r)
        {
            temp[i++] = arr[right];
            right++;
        }
        
        for(int j=l; j<=r; j++)
        {
            arr[j] = temp[j-l];
        }
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r)
            return;
            
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, r);
    }
};
