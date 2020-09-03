/*
Problem: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'.
Determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets
    Open brackets must be closed in the correct order

link: https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(auto c : str) {
            if(c=='(' || c=='{' || c=='[')
                s.push(c);
            else {
                if(s.empty()) return false;
                
                if(c == ')' && s.top() != '(') return false;
                if(c == '}' && s.top() != '{') return false;
                if(c == ']' && s.top() != '[') return false;
                s.pop();
            }
        }
        if(!s.empty()) return false;        
        return true;
    }
};