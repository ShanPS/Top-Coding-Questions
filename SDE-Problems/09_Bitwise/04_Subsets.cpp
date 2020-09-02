/*
Problem: Given a set of distinct integers, nums, return all possible subsets (the power set).

link: https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = pow(2, nums.size());
        
        for(int i=0; i<size; i++) {
            vector<int> subset;
            int num = i;
            int idx = 0;
            
            while(num) {
                if(num & 1)
                    subset.push_back(nums[idx]);
                
                num = num>>1;
                idx++;
            }
            ans.push_back(subset);
        }
        
        return ans;
    }
};