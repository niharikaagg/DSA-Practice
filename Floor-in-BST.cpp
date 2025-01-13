// https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.
*/



class Solution{

public:
    int floor(Node* root, int x) {
        int ans = -1;
        
        if(root == NULL)
            return ans;
            
        while(root != NULL)
        {
            if(root->data == x)
                return root->data;
                
            else if(root->data > x)
                root = root->left;
                
            else    // root->data < x
            {
                if(root->data > ans)
                    ans = root->data;
                    
                root = root->right;
            }
        }
        
        return ans;
    }
};
