/*
Problem: Given a string, find the length of the longest substring without repeating characters

link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[256];
        memset(index, -1, sizeof(index));
        int start = 0, n = s.size();
        int maxLen = 0;
        
        for(int i=0; i<n; i++) {
            int idx = s[i];
            if(index[idx] != -1 && index[idx] >= start)
                start = index[idx] + 1;
            
            index[idx] = i;
            maxLen = max(maxLen, i-start+1);
        }
        
        return maxLen;
    }
};