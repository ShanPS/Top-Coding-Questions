/*
Problem: Implement pow(x, n), which calculates x raised to the power n (ie. x^n) in O(logn) time

link: https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        double temp = myPow(x, n/2);
        if(n%2 == 0)
            return temp * temp;
        else {
            if(n > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
};