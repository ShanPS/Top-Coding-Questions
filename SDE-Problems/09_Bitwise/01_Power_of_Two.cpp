/*
Problem: Given an integer, write a function to determine if it is a power of two.

link: https://leetcode.com/problems/power-of-two/
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)  return false;
        
        n = n & (n-1);
        return n==0;
    }
};