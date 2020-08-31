/*
Problem: Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Note:
Since the return type is an integer, the decimal digits are truncated and only the integer part of 
the result is returned.

link: https://leetcode.com/problems/sqrtx/
*/

class Solution {
public:
    int mySqrt(int x) {
        int root = 0;
        int low = 1, high = x;
        while(low <= high) {
            long long mid = low + (high-low)/2;
            if(mid*mid <= x) {
                root = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return root;
    }
};