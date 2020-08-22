/*
Problem: Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

link: https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
	// Kadane’s Algorithm
    int maxSubArray(vector<int>& nums) {
        int answer = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            answer = max(answer, sum);
            
            if(sum < 0) sum = 0;
        }
        return answer;
    }
};