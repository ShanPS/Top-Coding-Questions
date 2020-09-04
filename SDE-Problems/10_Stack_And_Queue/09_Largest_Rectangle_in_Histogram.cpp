/*
Problem: Given n non-negative integers representing the histogram's bar height where the width 
of each bar is 1, find the area of largest rectangle in the histogram.

link: https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int tp, i=0, n=heights.size();
        int maxArea = 0;
        
        while(i<n) {
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else {
                tp = s.top();
                s.pop();
                maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i-s.top()-1));
            }
        }
        while(!s.empty()) {
            tp = s.top();
            s.pop();
            maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i-s.top()-1));
        }
        
        return maxArea;
    }
};