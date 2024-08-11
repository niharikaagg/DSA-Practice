// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

/*
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.
*/



class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head == NULL)
            return NULL;
            
        if(head->next == NULL)
            return head;
            
        Node* temp1 = head;
        Node* temp2 = head->next;
        
        while(temp2 != NULL)
        {
            temp1->next = temp1->prev;
            temp1->prev = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        
        temp1->next = temp1->prev;
        temp1->prev = NULL;
        head = temp1;
        
        return head;
    }
};
