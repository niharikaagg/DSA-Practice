// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.
*/



int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ans = -1;
    
    while(root!=NULL)
    {
        if(root->data == input)
            return root->data;
            
        else if(root->data < input)
            root = root->right;
            
        else    // root->data > input
        {
            ans = root->data;
            root = root->left;
        }
    }
    
    return ans;
}
