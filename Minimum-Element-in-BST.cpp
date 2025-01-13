// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.
*/



class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL)
            return NULL;
            
        while(root->left != NULL)
            root = root->left;
            
        return root->data;
    }
};
