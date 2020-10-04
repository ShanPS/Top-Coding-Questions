/*
Problem: Given two words word1 and word2, find the minimum number of operations required to 
convert word1 to word2.

You have the following 3 operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

link: https://leetcode.com/problems/edit-distance/
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        int dp[len1+1][len2+1];
        
        for(int i=0; i<=len1; i++) {
            for(int j=0; j<=len2; j++) {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
            
        
        return dp[len1][len2];
    }
};