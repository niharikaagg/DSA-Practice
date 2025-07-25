// https://leetcode.com/problems/implement-queue-using-stacks/description/

/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/



class MyQueue {
public:
    stack <int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            int p = s1.top();
            s1.pop();
            s2.push(p);
        }

        s1.push(x);

        while(!s2.empty())
        {
            int p = s2.top();
            s2.pop();
            s1.push(p);
        }
    }
    
    int pop() {
        int p = s1.top();
        s1.pop();
        return p;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
