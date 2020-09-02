/*
Problem: Given two integers dividend and divisor.
Divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.

Note:
The integer division should truncate toward zero, which means losing its fractional part.

link: https://leetcode.com/problems/divide-two-integers/
*/

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long quotient = 0, temp = 0;

        for(int i = 31; i >= 0; i--) {
            if(temp + (divisor << i) <= dividend) {
                temp += divisor << i;
                quotient |= 1LL << i;
            }
        }
        if(sign == 1 && quotient > INT_MAX)
            return INT_MAX;
        return sign * quotient;
    }
};