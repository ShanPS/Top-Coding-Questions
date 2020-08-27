/*
Problem: Given a sorted array nums, remove the duplicates in-place such that each element appear 
only once and return the new length.

Note:
Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        int uniqueNums = 1;
        for(int j=1; j<n; j++) {
            if(nums[uniqueNums-1] == nums[j]) continue;
            
            swap(nums[uniqueNums], nums[j]);
            uniqueNums++;
        }
        
        return uniqueNums;
    }
};