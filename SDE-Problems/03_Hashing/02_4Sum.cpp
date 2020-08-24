/*
Problem: Given an array nums of n integers and an integer target, are there elements a, b, c, and d 
in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

link: https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        // loop for first number
        for(int i = 0; i < n-3; i++) {
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break; // smallest sum greater than the target
            if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue; // biggest sum lesser than the target
            if(i >= 1 && nums[i] == nums[i-1]) continue; //remove duplicates
            
            // loop for second number
            for(int j = i + 1; j < n - 2; ++j) {
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                if(j >= i + 2 && nums[j] == nums[j - 1]) continue; // remove duplicates
                
                // from here it is two sum problem
                int left = j + 1, right = n - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target || (left >= j + 2 && nums[left] == nums[left-1])) left++;
                    else if(sum > target || (right <= n - 2 && nums[right] == nums[right+1])) right--;
                    else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }
            }
        }
        
        return res;
    }
};