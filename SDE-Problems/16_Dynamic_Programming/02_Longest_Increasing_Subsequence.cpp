/*
Problem: Given an unsorted array of integers, find the length of longest increasing subsequence.

link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

// DP -- O(n^2)
class Solution {
	int lengthOfLIS(vector<int>& nums) {
	    int n = nums.size();
	    if(n == 0) return 0;
	    int LIS[n];
	    
	    LIS[0] = 1;
	    for(int i=1; i<n; i++) {
	        LIS[i] = 1;
	        for(int j=0; j<i; j++) {
	            if(nums[i] > nums[j])
	                LIS[i] = max(LIS[i], 1 + LIS[j]);
	        }
	    }
	    
	    return *max_element(LIS, LIS + n);
	}
};



// DP -- O(nlogn)
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

// class Solution {
//     int ceilIndex(vector<int>& ends, int l, int r, int key) {
//         while(r - l > 1) {
//             int m = l + (r - l) / 2;

//             if (ends[m] >= key) r = m;
//             else l = m;
//         }
//         return r;
//     }
    
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
        
//         vector<int> ends(nums.size(), 0);
//         int length = 1;
        
//         ends[0] = nums[0];
//         for(int i = 1; i < nums.size(); i++) {
//             if(nums[i] < ends[0])
//                 ends[0] = nums[i];
//             else if(nums[i] > ends[length - 1])
//                 ends[length++] = nums[i];
//             else
//                 ends[ceilIndex(ends, -1, length - 1, nums[i])] = nums[i]; 
//         }
        
//         return length;
//     }
// };