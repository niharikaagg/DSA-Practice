// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootInorder = mp[root->val];
        int numsOnLeftInorder = rootInorder - inStart;

        root->left = build(preorder, preStart+1, preStart+numsOnLeftInorder, inorder, inStart, rootInorder-1, mp);
        root->right = build(preorder, preStart+numsOnLeftInorder+1, preEnd, inorder, rootInorder+1, inEnd, mp);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

        return root;
    }
};
