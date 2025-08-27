// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

/*
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
*/



// User function template for C++
class Solution {
  public:
    int lowerBound(vector<vector<int>> &arr, int row)
    {
        int s = 0, e = arr[0].size()-1;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(arr[row][mid] == 1)
                e = mid - 1;
                
            else
                s = mid + 1;
        }
        
        return s;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr[0].size();
        int max1s = 0;
        int indexMax1s = -1;
        
        for(int i=0; i<arr.size(); i++)
        {
            int numberOf1s = n - lowerBound(arr, i);
            if(numberOf1s > max1s)
            {
                max1s = numberOf1s;
                indexMax1s = i;
            }
        }
        
        return indexMax1s;
    }
};
