// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
*/



class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        vector <int> ans;
        
        int i=0, j=0;
        
        ans.push_back(min(a[i], b[i]));
        
        while(i<a.size() and j<b.size())
        {
            if(a[i] == ans.back())
            {
                i++;
                continue;
            }
            
            if(b[j] == ans.back())
            {
                j++;
                continue;
            }
            
            if(a[i] <= b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i<a.size())
        {
            if(a[i] == ans.back())
            {
                i++;
                continue;
            }
            
            ans.push_back(a[i]);
            i++;
        }
        
        while(j<b.size())
        {
            if(b[j] == ans.back())
            {
                j++;
                continue;
            }
            
            ans.push_back(b[j]);
            j++;
        }
        
        return ans;        
        
        
        
        // vector<int> ans;
        
        // int i=0, j=0;
        
        // while(i<a.size() and j<b.size())
        // {
        //     if(a[i] <= b[j])
        //     {
        //         ans.push_back(a[i]);
        //         i++;
        //     }
            
        //     else
        //     {
        //         ans.push_back(b[j]);
        //         j++;
        //     }
            
        //     while(a[i] == ans.back())
        //         i++;
                
        //     while(b[j] == ans.back())
        //         j++;
        // }
        
        // while(i<a.size())
        // {
        //     ans.push_back(a[i]);
        //     i++;
            
        //     while(a[i] == ans.back())
        //         i++;
        // }
        
        // while(j<b.size())
        // {
        //     ans.push_back(b[j]);
        //     j++;
            
        //     while(b[j] == ans.back())
        //         j++;
        // }
        
        // return ans;
    }
};
