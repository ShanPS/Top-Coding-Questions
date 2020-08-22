/*
Problem: Given an array nums containing n+1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist.
Assume that there is only one duplicate number, find the duplicate one.

Note:
1. You must not modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than O(n^2).
4. There is only one duplicate number in the array, but it could be repeated more than once.


link: https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution {
    int solveUsingFloydsTortoiseAndHare(vector<int>& nums) {
        // First find the intersection point of tortoise and hare.
        // It will be inside the cylce but may not be the starting point of cycle.
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];  // taking one step
            hare = nums[nums[hare]];    // taking two steps
        } while(tortoise != hare);
        
        // Now tortoise and hare are at the intersection point.
        // Reset tortoise to initial point and slow down the hare (take only one step at a time).
        // Then their intersection point will give us the entrance to the cycle (duplicate number).
        tortoise = nums[0];
        while(tortoise != hare) {
            tortoise = nums[tortoise];  // taking one step
            hare = nums[hare];          // taking one step
        }
        
        return hare;
    }
    
    int solveUsingDivideAndConquer(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n-1;
        
        while(true) {
            int num = l + (r-l)/2;
            int count=0, countl=0, countr=0;
            
            for(auto x:nums) {
                if(x == num)
                    count++;
                else if(x > num && x <= r)
                    countr++;
                else if(x < num && x >= l)
                    countl++;
            }            
            if(count>1)
                return num;
            
            if(countl >= countr)
                r = num-1;
            else
                l = num+1;
        }
    }
public:
    int findDuplicate(vector<int>& nums) {
        // cycle detection algorithm --> O(n) time and O(1) space
        return solveUsingFloydsTortoiseAndHare(nums);
        
        // return solveUsingDivideAndConquer(nums);   // O(nlogn) time and O(1) space
    }
};