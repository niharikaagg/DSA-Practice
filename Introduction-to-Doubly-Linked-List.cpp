// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

/*
Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list in the same way that we access the next element. His teacher explains doubly linked lists to him.

Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.
*/



class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        if(arr.empty())
            return NULL;
            
        Node* head = new Node(arr[0]);
            
        if(arr.size() == 1)
            return head;
        
        Node* current = head;
        
        for(int i=1; i<arr.size(); i++)
        {
            Node* newNode = new Node(arr[i]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        
        return head;
    }
};
