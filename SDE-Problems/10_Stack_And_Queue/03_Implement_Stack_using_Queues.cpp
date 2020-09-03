/*
Problem: Implement the following operations of a stack using queues
    push(x) -- Push element x onto stack
    pop()   -- Removes the element on top of the stack
    top()   -- Get the top element
    empty() -- Return whether the stack is empty


link: https://leetcode.com/problems/implement-stack-using-queues/
*/

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */