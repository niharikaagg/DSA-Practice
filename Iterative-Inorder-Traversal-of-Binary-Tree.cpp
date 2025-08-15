// https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> inorder;
        stack<TreeNode*> s;
        TreeNode* node = root;

        while(true)
        {
            if(node != NULL)
            {
                s.push(node);
                node = node->left;
            }

            else
            {
                if(s.empty())
                    break;

                node = s.top();
                s.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};
