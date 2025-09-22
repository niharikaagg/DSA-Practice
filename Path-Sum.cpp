// https://leetcode.com/problems/path-sum/

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
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
    bool getSum(TreeNode* root, int targetSum, int currentSum)
    {
        if(root == NULL)
            return false;

        currentSum += root->val;

        if(root->left==NULL && root->right==NULL)
            return currentSum == targetSum;

        return (getSum(root->left, targetSum, currentSum) || getSum(root->right, targetSum, currentSum));

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return getSum(root, targetSum, 0);
    }
};
