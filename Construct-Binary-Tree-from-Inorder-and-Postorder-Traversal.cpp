// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& mp)
    {
        if(inStart>inEnd || postStart>postEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootInorder = mp[root->val];
        int numsOnLeftInorder = rootInorder-inStart;

        root->left = build(inorder, inStart, rootInorder-1, postorder, postStart, postStart+numsOnLeftInorder-1, mp);
        root->right = build(inorder, rootInorder+1, inEnd, postorder, postStart+numsOnLeftInorder, postEnd-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);

        return root;
    }
};
