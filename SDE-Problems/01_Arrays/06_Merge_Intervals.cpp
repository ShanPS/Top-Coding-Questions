/*
Problem: Given a collection of intervals, merge all overlapping intervals.

link: https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        
        vector<vector<int>> mergedIntervals;
        vector<int> interval;
        
        sort(intervals.begin(), intervals.end());
        interval = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= interval[1]) {
                interval[1] = max(interval[1], intervals[i][1]);
            }
            else {
                mergedIntervals.push_back(interval);
                interval = intervals[i];
            }
        }
        mergedIntervals.push_back(interval);
        
        return mergedIntervals;
    }
};