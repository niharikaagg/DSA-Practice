// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

/*
Implement a Stack using a Linked List, this stack has no fixed capacity and can grow dynamically until memory is available.
The Stack must support the following operations:

(i) push(x): Insert an element x at the top of the stack.
(ii) pop(): Remove the element from the top of the stack.
(iii) peek(): Return top element if not empty, else -1.
(iv) isEmpty(): Return true if the stack is empty else return false.
(v) size(): Return the number of elements currently in the stack.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call push(x)
2: Call pop()
3: Call peek()
4: Call isEmpty()
5: Call size()
You just have to implement the functions push, pop, peek,  isEmpty and size. The driver code will handle the input and output.
*/



/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    Node* top;
    int count;

  public:
    myStack() {
        top = NULL;
        count = 0;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int x) {
        Node* node = new Node(x);
        
        if(top == NULL)
            top = node;
        else
        {
            node->next = top;
            top = node;
        }
        
        count++;
    }

    void pop() {
        if(top == NULL)
            return;
            
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    int peek() {
        if(top == NULL)
            return -1;
        
        return top->data;
    }

    int size() {
        return count;
    }
};
