// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.
*/



/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head)
    {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        Node* back = NULL;
        Node* current = head;
        Node* front = head->next;

        while(front != NULL)
        {
            current->next = back;
            back = current;
            current = front;
            front = front->next;
        }
        current->next = back;
        head = current;

        return head;
    }
  
    Node* addOne(Node* head) {
        head = reverseList(head);
        
        Node* temp = head;
        
        while(temp != NULL && temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }
        
        if(temp == NULL)
        {
            Node* newNode = new Node(1);
            head = reverseList(head);
            newNode->next = head;
            head = newNode;
        }
        else
        {
            temp->data = temp->data + 1;
            head = reverseList(head);
        }
        
        return head;
    }
};


// without reversal, single pass

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {        
        Node* lastNotNine = NULL;
        Node* temp = head;
        
        while(temp != NULL)
        {
            if(temp->data != 9)
                lastNotNine = temp;
                
            temp = temp->next;
        }
        
        if(lastNotNine == NULL)
        {
            Node* newNode = new Node (1);
            newNode->next = head;
            head = newNode;
            lastNotNine = head;
        }
        else
        {
            lastNotNine->data += 1;
        }
        
        while(lastNotNine->next != NULL)
        {
            lastNotNine = lastNotNine->next;
            lastNotNine->data = 0;
        }
        
        return head;
    }
};
