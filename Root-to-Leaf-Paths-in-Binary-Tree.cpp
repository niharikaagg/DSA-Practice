// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.
*/



/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root)
    {
        return (root->left==NULL && root->right==NULL);
    }
    
    void getPath(Node* root, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root == NULL)
            return;
        
        path.push_back(root->data);
        
        if(isLeaf(root))
            ans.push_back(path);
        
        else
        {
            if(root->left)
                getPath(root->left, path, ans);
                
            if(root->right)
                getPath(root->right, path, ans);
        }
            
        // to remove elements from path on going back (backtrack)
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        
        getPath(root, path, ans);
        
        return ans;
    }
};
