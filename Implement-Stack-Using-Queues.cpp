// https://leetcode.com/problems/implement-stack-using-queues/description/

/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/



class MyStack {
public:
    queue <int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty())
        {
            int p = q1.front();
            q1.pop();
            q2.push(p);
        }

        q1.push(x);

        while(!q2.empty())
        {
            int p = q2.front();
            q2.pop();
            q1.push(p);
        }        
    }
    
    int pop() {
        int p = q1.front();
        q1.pop();
        return p;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
