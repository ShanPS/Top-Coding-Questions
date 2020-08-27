/*
Problem: Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

link: https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
      
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++) {
            if(i>0 && nums[i-1]==nums[i]) continue;
            if(nums[i]+nums[n-2]+nums[n-1] < 0) continue;
            if(nums[i]+nums[i+1]+nums[i+2] > 0) break;
            
            int left=i+1, right=n-1;
            while(left < right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left<right && nums[left-1]==nums[left]) left++;
                    while(right>left && nums[right]==nums[right+1]) right--;
                }
            }
        }
        
        return res;
    }
};