// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
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
    int minDiff = INT_MAX;
    TreeNode* prev = NULL;

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return minDiff;

        getMinimumDifference(root->left);

        if(prev != NULL)
            minDiff = min(minDiff, root->val - prev->val);
        prev = root;

        getMinimumDifference(root->right);

        return minDiff;
    }
};
