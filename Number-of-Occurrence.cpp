// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
*/



class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int s=0, e=n-1, left=-1;
	    
	    while(s<=e)
	    {
            int mid = s+(e-s)/2;
	        
	        if(arr[mid] == x)
	        {
	            left = mid;
	            e = mid-1;
	        }
	        
	        else if(arr[mid] < x)
	            s = mid+1;
	            
	        else if(arr[mid] > x)
	            e = mid-1;
	    }
	    
	    if(left == -1)
	        return 0;
	        
	    s=left+1, e=n-1;
	    int right=left;
	    
	    while(s<=e)
	    {
	        int mid = s+(e-s)/2;
	        
	        if(arr[mid] == x)
	        {
	            right = mid;
	            s = mid+1;
	        }
	        
	        else if(arr[mid] < x)
	            s = mid+1;
	            
	        else if(arr[mid] > x)
	            e = mid-1;
	    }
	    
	    return right-left+1;
	}
};
