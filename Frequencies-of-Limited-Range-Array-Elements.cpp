// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

/*
You are given an array arr[] containing n positive integers. These integers can be from 1 to p, and some numbers may be repeated or absent. Your task is to count the frequency of all numbers that lie in the range 1 to n.
Do modify the array in-place changes in arr[], such that arr[i] = frequency(i) and assume 1-based indexing.

Note: The elements greater than n in the array can be ignored for counting.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int count[N] = {0};
        for(int i=0; i<N; i++)
        {
            if (arr[i] > N)
                continue;
            count[arr[i]-1]++;
        }
        for(int i=0; i<N; i++)
            arr[i] = count[i];
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}

// } Driver Code Ends
