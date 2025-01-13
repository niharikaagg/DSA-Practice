// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode* temp = root;

        while(1)
        {
            if(temp->val > val)
            {
                if(temp->left == NULL)
                    break;
                temp = temp->left;
            }

            else if(temp->val < val)
            {
                if(temp->right == NULL)
                    break;
                temp = temp->right;
            }
        }

        if(temp->val > val)
            temp->left = new TreeNode(val);
        else
            temp->right = new TreeNode(val);

        return root;
    }
};
