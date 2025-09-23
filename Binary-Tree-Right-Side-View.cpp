// https://leetcode.com/problems/binary-tree-right-side-view/

/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    void view(TreeNode* root, int level, vector<int>& res)
    {
        if(root == NULL)
            return;

        if(level == res.size())
            res.push_back(root->val);

        // root right left
        view(root->right, level+1, res);
        view(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        view(root, 0, res);
        return res;
    }
};
