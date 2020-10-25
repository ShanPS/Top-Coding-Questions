/*
Problem: You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Note: You may assume that you have an infinite number of each kind of coin.

link: https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int numCoins = coins.size();
        int dp[numCoins+1][amount+1];
        memset(dp, -1, sizeof(dp));
        
        for(int curCoinIdx = 1; curCoinIdx <= numCoins; curCoinIdx++) {
            int coinVal = coins[curCoinIdx-1];
            
            for(int curAmount = 1; curAmount <= amount; curAmount++) {
                if(curAmount < coinVal)
                    dp[curCoinIdx][curAmount] = dp[curCoinIdx-1][curAmount];
                else if(curAmount == coinVal)
                    dp[curCoinIdx][curAmount] = 1;
                else {
                    if(dp[curCoinIdx][curAmount-coinVal] == -1)
                        dp[curCoinIdx][curAmount] = dp[curCoinIdx-1][curAmount];
                    else if(dp[curCoinIdx-1][curAmount] == -1)
                        dp[curCoinIdx][curAmount] = 1 + dp[curCoinIdx][curAmount-coinVal];
                    else
                        dp[curCoinIdx][curAmount] = min(1 + dp[curCoinIdx][curAmount-coinVal], dp[curCoinIdx-1][curAmount]);
                }
            }
        }
        
        if(dp[numCoins][amount] == -1) 
            return -1;
        return dp[numCoins][amount];
    }
};


// BETTER SOLUTION
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int dp[amount+1];

//         for(int i=0; i<=amount; i++) {
//             if(i == 0) dp[i] = 0;
//             else dp[i] = INT_MAX;
//         }

//         for(int i=1; i<=amount; i++) {
//             int ans = INT_MAX;
//             for(int j=0 ; j<coins.size(); j++) {
//                 int coin = coins[j];
                
//                 if(coin <= i)
//                     ans = min(ans, dp[i-coin]);
//             }
            
//             dp[i] = (ans == INT_MAX ? INT_MAX : 1 + ans);
//         }

//         return dp[amount] == INT_MAX ? -1 : dp[amount];
//     }
// };