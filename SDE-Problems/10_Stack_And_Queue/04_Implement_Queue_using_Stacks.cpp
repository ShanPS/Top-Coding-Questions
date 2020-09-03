/*
Problem: Implement the following operations of a queue using stacks
    push(x) -- Push element x to the back of queue
    pop()   -- Removes the element from in front of queue
    peek()  -- Get the front element
    empty() -- Return whether the queue is empty


link: https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() { 
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int frontElement = s1.top();
        s1.pop();
        return frontElement;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */