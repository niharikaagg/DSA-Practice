// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/



/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root)
    {
        return (root->left == NULL && root->right == NULL);
    }
    
    void leftBoundary(Node* root, vector<int> &ans)
    {
        Node* n = root->left;
        
        while(n!=NULL && !isLeaf(n))
        {
            ans.push_back(n->data);
            
            if(n->left != NULL)
                n = n->left;
            else
                n = n->right;
        }
    }
    
    void rightBoundary(Node* root, vector<int> &ans)
    {
        vector<int> temp;
        Node* n = root->right;
        
        while(n!=NULL && !isLeaf(n))
        {
            temp.push_back(n->data);
            
            if(n->right != NULL)
                n = n->right;
            else
                n = n->left;
        }
        
        // we need to add nodes from right boundary in reverse order (down to up)
        for(int i=temp.size()-1; i>=0; i--)
        {
            ans.push_back(temp[i]);
        }
    }
    
    // preorder traversal to find leaves
    void getLeaves(Node* root, vector<int> &ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)
            getLeaves(root->left, ans);
            
        if(root->right)
            getLeaves(root->right, ans);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        // push root to ans if it is not a leaf node, otherwise it will be added from leaves function as well
        if(!isLeaf(root))
            ans.push_back(root->data);
        
        leftBoundary(root, ans);
        getLeaves(root, ans);
        rightBoundary(root, ans);
        
        return ans;
    }
};
