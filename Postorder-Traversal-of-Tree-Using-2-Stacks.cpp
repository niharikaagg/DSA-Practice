// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode* root) {       
        vector<int> postorder;

        if(root == NULL)
            return postorder;

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        TreeNode* node = root;
        s1.push(node);

        while(!s1.empty())
        {
            node = s1.top();
            s1.pop();
            s2.push(node);

            if(node->left != NULL)
                s1.push(node->left);
            if(node->right != NULL)
                s1.push(node->right);
        }

        while(!s2.empty())
        {
            node = s2.top();
            s2.pop();
            postorder.push_back(node->val);
        }

        return postorder;
    }
};
