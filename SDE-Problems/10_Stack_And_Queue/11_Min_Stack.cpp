/*
Problem: Design a stack that supports push, pop, top, and getMin in constant time
    push(x)  -- Push element x onto stack
    pop()    -- Removes the element on top of the stack
    top()    -- Get the top element
    getMin() -- Retrieve the minimum element in the stack

link: https://leetcode.com/problems/min-stack/
*/

class MinStack {
    stack<int> s, sMin;
public:
    MinStack() {
    }
    
    void push(int x) {
        if(sMin.empty() || x <= sMin.top()) 
            sMin.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.top() == sMin.top())
            sMin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return sMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */