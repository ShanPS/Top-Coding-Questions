/*
Problem: You are given a sorted array consisting of only integers where every element appears 
exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Note:
Your solution should run in O(log n) time and O(1) space.

link: https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int left=0, right=n-1;
        while(left < right) {
            int mid = left + (right-left)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) 
                return nums[mid];
            if(nums[mid]==nums[mid-1]) {
                if((mid-left)%2 == 0) right = mid-2;
                else left = mid+1;
            }
            else {
                if((right-mid)%2 == 0) left = mid+2;
                else right = mid-1;
            }
        }
        return nums[left];
    }
};