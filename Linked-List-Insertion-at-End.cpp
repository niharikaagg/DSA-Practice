// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

/*
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.
*/



class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        
        if(head == NULL)
        {
            Node* newNode = new Node(x);
            head = newNode;
            return head;
        }
        
        Node* current = head;
        
        while(current->next!=NULL)
            current = current->next;
            
        Node* newNode = new Node(x);
        current->next = newNode;
        
        return head;
    }
};
