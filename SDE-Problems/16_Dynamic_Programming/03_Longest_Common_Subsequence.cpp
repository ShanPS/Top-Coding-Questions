/*
Problem: Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters. 
(eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings 
is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

link: https://leetcode.com/problems/longest-common-subsequence/
*/


// BOTTOM-UP APPROACH
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};

// TOP-DOWN APPROACH
// class Solution {
//     string s1, s2;
//     int lcs(vector<vector<int>>& DP, int n1, int n2) {
//         if(n1 == -1 || n2 == -1)
//             return 0;

//         if(DP[n1][n2] == -1) {
//             if(s1[n1] == s2[n2])
//                 DP[n1][n2] = 1 + lcs(DP, n1-1, n2-1);
//             else
//                 DP[n1][n2] = max(lcs(DP, n1, n2-1), lcs(DP, n1-1, n2));
//         }

//         return DP[n1][n2];
//     }

// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         s1 = text1;
//         s2 = text2;
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> DP(n1, vector<int>(n2, -1));
        
//         return lcs(DP, n1-1, n2-1);
//     }
// };