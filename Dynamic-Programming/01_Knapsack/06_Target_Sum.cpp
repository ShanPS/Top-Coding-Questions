/*
Problem: You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

link: https://leetcode.com/problems/target-sum/
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto num : nums) sum += num;
        
        if(sum < S || (sum - S) % 2) return 0;
        
        int target = (sum - S)/2;
        int n = nums.size();
        int t[n+1][target+1];
        
        for(int i=0; i<=n; i++) t[i][0] = 1;
        for(int j=1; j<=target; j++) t[0][j] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=target; j++) { // Note: j starts from 0 as 0 can be an element in nums
                if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][target];
    }
};