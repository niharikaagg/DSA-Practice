// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/*
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.
*/



/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* root1, Node* root2)
    {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(root1 != NULL && root2 != NULL)
        {
            if(root1->data < root2->data)
            {
                temp->bottom = root1;
                root1 = root1->bottom;
            }
            else
            {
                temp->bottom = root2;
                root2 = root2->bottom;
            }
            
            temp = temp->bottom;
            temp->next = NULL; // make sure next of every node is null since we have to make the list towards the bottom
        }
        
        temp->bottom = root1 ? root1 : root2;
        
        return dummy->bottom;
    }
  
    Node *flatten(Node *root) {
        // we have to create a vertical liked list (towards the bottom)
        // we will move to the last node recursively, and on coming back we will merge them
        
        // base case
        if(root == NULL || root->next == NULL)
            return root;
            
        Node* mergedRoot = flatten(root->next); // move forward till you find base case (last node)
        root = merge(root, mergedRoot); // updated root after merge
        return root;
    }
};
