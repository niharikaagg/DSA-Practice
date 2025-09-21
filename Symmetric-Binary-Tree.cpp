// https://leetcode.com/problems/symmetric-tree/

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findSymmetry(TreeNode* left, TreeNode* right)
    {
        if(left==NULL && right==NULL)
            return true;
        if(left==NULL || right==NULL)
            return false;

        // alternative
        // if(left==NULL && right==NULL)
        //     return left == right;

        if(left->val != right->val)
            return false;

        return findSymmetry(left->left, right->right) && findSymmetry(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        return findSymmetry(root->left, root->right);
    }
};
