// https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;

        return false;
    }
};


// ***** OPTIMIZED (O(N^2) to O(N))*****

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
    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lh = getHeight(root->left);
        if(lh == -1) return -1;

        int rh = getHeight(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return (getHeight(root) != -1);
    }
};
