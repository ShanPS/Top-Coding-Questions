/*
Problem: Sort an array of 0s 1s and 2s without using extra space.

Note: 
1. don't use sorting algorithm
2. Try to make O(n) time and O(1) space solution

link: https://leetcode.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};