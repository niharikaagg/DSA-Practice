// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

/*
Given an array of arr[] and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).
*/




class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans;
        
        for(int index : indices)
        {
            int count = 0;
            
            for(int i=index+1; i<n; i++)
            {
                if(arr[i] > arr[index])
                    count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};
