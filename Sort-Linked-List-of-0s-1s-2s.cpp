// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.
*/



/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // brute force is to keep counters for 0s, 1s, and 2s and then element replacement in the list
        // it takse 2 traversals - O(2N)
        
        if(head == NULL)
            return NULL;
        
        // heads
        Node* head0 = new Node(-1);
        Node* head1 = new Node(-1);
        Node* head2 = new Node(-1);
        
        // pointers for traversal and tracking
        Node* temp0 = head0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(head != NULL)
        {
            if(head->data == 0)
            {
                temp0->next = head;
                temp0 = temp0->next;
            }
            
            else if(head->data == 1)
            {
                temp1->next = head;
                temp1 = temp1->next;
            }
            
            else
            {
                temp2->next = head;
                temp2 = temp2->next;
            }
            
            head = head->next;
        }
        
        temp2->next = NULL;
        temp1->next = head2->next;  // this is imp first in case there are no 1s, then 0 will directly connect to 2
        temp0->next = head1->next;
            
        return head0->next;
        
    }
};
