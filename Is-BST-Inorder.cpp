// https://www.geeksforgeeks.org/problems/binary-search-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search-trees

/*
Given an array of integers arr[] representing inorder traversal of elements of a binary tree. Return true if the given inorder traversal can be of a valid Binary Search Tree.

Note - In a valid Binary Search Tree all keys are unique.
*/



class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] >= arr[i+1])
                return false;
        }
        return true;
    }
};
