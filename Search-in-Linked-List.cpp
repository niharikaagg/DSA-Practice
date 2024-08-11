// https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

/*
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.
*/



class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        
        if(head==NULL)
            return false;
            
        Node* current = head;
        
        for(int i=0; i<n; i++)
        {
            if(current->data == key)
                return true;
            current = current->next;
        }
        
        return false;
    }
};
