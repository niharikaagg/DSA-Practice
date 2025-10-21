// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

/*
Implement a Queue using a Linked List, this queue has no fixed capacity and can grow dynamically until memory is available.
The Queue must support the following operations:

(i) enqueue(x): Insert an element x at the rear of the queue.
(ii) dequeue(): Remove the element from the front of the queue.
(iii) getFront(): Return front element if not empty, else -1.
(iv) isEmpty(): Return true if the queue is empty else return false.
(v) size(): Return the number of elements currently in the queue.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2: Call dequeue()
3: Call getFront()
4: Call isEmpty()
5: Call size()
You just have to implement the functions enqueue, dequeue, getFront,  isEmpty and size. The driver code will handle the input and output.
*/



class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node* front;
    Node* back;
    int count;

  public:
    myQueue() {
        front = NULL;
        back = NULL;
        count = 0;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int x) {
        Node* node = new Node(x);
        
        if(front == NULL)
        {
            front = node;
            back = node;
        }
        else
        {
            back->next = node;
            back = back->next;
        }
        
        count++;
    }

    void dequeue() {
        if(front == NULL)
            return;
        
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
    }

    int getFront() {
        if(front == NULL)
            return -1;
        return front->data;
    }

    int size() {
        return count;
    }
};
