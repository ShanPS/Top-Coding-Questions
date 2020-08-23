/*
Problem: Given an integer n, return the number of trailing zeroes in n!

link: https://leetcode.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        long long num = 5;
        int count = 0;

        while(n/num) {
            count += n/num;
            num = num * 5;
        }
        
        return count;
    }
};