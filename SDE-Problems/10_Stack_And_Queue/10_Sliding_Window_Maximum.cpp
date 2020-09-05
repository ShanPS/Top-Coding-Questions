/*
Problem: Given an array A and an integer K. 
Find the maximum for each and every contiguous subarray of size K.

Follow up:
Could you solve it in linear time?

link: https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq(k);
        int n = nums.size();
        
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k; i<n; i++) {
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        return ans;
    }
};