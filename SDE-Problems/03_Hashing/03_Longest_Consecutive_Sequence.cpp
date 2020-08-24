/*
Problem: Given an unsorted array of integers.
find the length of the longest consecutive elements sequence.

Note:
Your algorithm should run in O(n) complexity.

link: https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto n : nums)
            s.insert(n);
        
        int longest = 0;
        for(auto n : nums) {
            if(s.find(n-1) == s.end()) {
                int curNum = n;
                int curLen = 1;
                while(s.find(curNum+1) != s.end()) {
                    curLen++;
                    curNum++;
                }
                longest = max(longest, curLen);
            }
        }
        return longest;
    }
};