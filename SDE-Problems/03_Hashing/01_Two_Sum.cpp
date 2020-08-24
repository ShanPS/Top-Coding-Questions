/*
Problem: Given an array of integers, return indices of the two numbers such that they add up 
to a specific target. You may assume that each input would have exactly one solution, and you 
should not use the same element twice.

link: https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
            
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(m.find(target-nums[i]) != m.end()) {
                result.push_back(m[target-nums[i]]);
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        
        return result;
    }
};