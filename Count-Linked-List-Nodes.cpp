// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list

/*
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.
*/



class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        if(head==NULL)
            return 0;
            
        int count=0;
        Node* current = head;
        
        while(current != NULL)
        {
            count++;
            current = current->next;
        }
        
        return count;
    }
};
