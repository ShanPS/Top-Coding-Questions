/*
Problem: Given a non-empty string str and a dictionary wordDict containing a list of non-empty words, 
determine if str can be segmented into a space-separated sequence of one or more dictionary words.

Note:
1. The same word in the dictionary may be reused multiple times in the segmentation.
2. You may assume the dictionary does not contain duplicate words.


link: https://leetcode.com/problems/word-break/
*/


class Solution {
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        int strLen = str.length();
        if(strLen == 0) return true;
        
        vector<bool> dp(strLen+1, false);
        string temp;
        
        dp[0] = true;
        for(int i=0; i<strLen; i++) {
            if(dp[i] == true) {
                for(auto word : wordDict) {
                    int wordLen = word.length();
                    temp = str.substr(i, wordLen);
                    
                    if(word == temp) {
                        dp[i+wordLen] = true;
                        
                        if(i+wordLen == strLen)
                            return true;
                    }                    
                }
            }
        }
        return dp[strLen];
    }
};