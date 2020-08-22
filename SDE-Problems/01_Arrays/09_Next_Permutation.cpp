/*
Problem: Implement next permutation, which rearranges numbers into the lexicographically next greater 
permutation of numbers. If such arrangement is not possible, it must rearrange it as the lowest possible 
order (ie, sorted in ascending order). The replacement must be in-place and use only constant extra 
memory.

link: https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	// Find the index of first element in a pair of adjacent elements num[i-1] & num[i] 
    	// from right, such that nums[i-1] < nums[i]
        int idx = -1;
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i-1] < nums[i]) {
                idx = i-1;
                break;
            }
        }
        // If no such pair present then the elements are in decreasing order.
        // So reverse the whole array to get next permutation (ie, array in increasing order).
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // But if such a pair is present then find the first larger element than nums[idx]
        // from right and swap them. Then reverse all the elements to the right of idx to get 
        // the next permutation. 
        for(int i=nums.size()-1; i>idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
};