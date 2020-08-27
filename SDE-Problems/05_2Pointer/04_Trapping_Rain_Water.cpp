/*
Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

link: https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), waterTrapped = 0;
        if(n==0) return 0;
        
        int leftMax = 0, rightMax = 0;
        int left = 0, right=n-1;
        
        while(left <= right) {
            if(height[left] < height[right]) {
                if(height[left] > leftMax) leftMax = height[left];
                else waterTrapped += leftMax - height[left];
                
                left++;
            }
            else {
                if(height[right] > rightMax) rightMax = height[right];
                else waterTrapped += rightMax - height[right];
                
                right--;
            }
        }
        
        return waterTrapped;
    }
};