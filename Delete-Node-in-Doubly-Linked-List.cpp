// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

/*
Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.
*/



class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        
        if(head->next == NULL)
        {
            delete head;
            return NULL;
        }
        
        Node* temp = head;
            
        if(x==1)
        {
            head = head->next;
            delete temp;
            return head;
        }
        
        int i=1;
        while(temp!=NULL && i<x)
        {
            temp = temp->next;
            i++;
        }
        
        if(temp == NULL)
            return head;
        
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        
        
        delete temp;
        
        return head;
    }
};
