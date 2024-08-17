// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};
