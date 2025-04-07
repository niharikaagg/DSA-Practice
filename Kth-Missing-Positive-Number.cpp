// https://leetcode.com/problems/kth-missing-positive-number/description/

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            int missing = arr[mid] - mid - 1;

            if(missing < k)
                low = mid+1;
            else
                high = mid-1;
        }

        return k + high + 1;
    }
};
