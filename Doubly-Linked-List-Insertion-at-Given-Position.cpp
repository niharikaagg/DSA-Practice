// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

/*
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.
*/



void addNode(Node *head, int pos, int data)
{
    
    Node* newNode = new Node(data);
    
    if(head==NULL)
    {
        head = newNode;
        return;
    }
   
    Node* current = head;
   
    int i=0;
    while(current!=NULL && i<pos)
    {
        current = current->next;
        i++;
    }
    
    if(current == NULL)
    {
        delete newNode;
        return;
    }
       
    newNode->next = current->next;
    if(current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}
