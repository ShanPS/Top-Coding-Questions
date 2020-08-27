/*
Problem: Given a binary array, find the maximum number of consecutive 1s in this array.

link: https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOnes = 0, ones = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) ones++;
            else if(ones) {
                maxOnes = max(maxOnes, ones);
                ones = 0;
            }
        }
        maxOnes = max(maxOnes, ones);
        
        return maxOnes;
    }
};