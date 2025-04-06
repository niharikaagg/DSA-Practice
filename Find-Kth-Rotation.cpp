// https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

/*
Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]
*/



class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        
        int low = 0, high = n-1, ans = INT_MAX, index = -1;
        
        while(low <= high)
        {
            if(arr[low] <= arr[high])
            {
                if(arr[low] <= ans)
                {
                    ans = min(ans, arr[low]);
                    index = low;
                }
                break;
            }
            
            int mid = low+(high-low)/2;
            
            if(arr[low] <= arr[mid])    // left sorted
            {
                if(arr[low] <= ans)
                {
                    ans = min(ans, arr[low]);
                    index = low;
                }
                low = mid+1;
            }
            
            else    // right sorted
            {
                if(arr[mid] <= ans)
                {
                    ans = min(ans, arr[mid]);
                    index = mid;
                }
                high = mid-1;
            }
        }
        
        return index;
    }
};
