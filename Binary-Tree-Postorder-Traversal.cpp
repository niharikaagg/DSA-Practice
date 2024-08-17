// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

    void postorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};
