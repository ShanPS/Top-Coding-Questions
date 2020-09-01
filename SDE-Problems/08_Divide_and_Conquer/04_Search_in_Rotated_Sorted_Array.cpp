/*
Problem: Given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might 
become [4,5,6,7,0,1,2]).
You should search for target in nums and if you found return its index, otherwise return -1.

link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& A, int target) {
        int n = A.size();
        int left = 0, right = n-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(target == A[mid]) return mid;
            
            if(A[left] <= A[mid]) {
                if(A[left] <= target && target <= A[mid]) right = mid-1;
                else left = mid+1;
            }
            else {
                if(A[mid] <= target && target <= A[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};