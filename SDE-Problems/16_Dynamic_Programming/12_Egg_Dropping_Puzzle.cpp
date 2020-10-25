/*
Problem: Suppose you have N eggs and you want to determine from which floor in a K-floor building you 
can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you 
need in order find the critical floor in the worst case while using the best strategy.

There are few rules given below :
1. An egg that survives a fall can be used again.
2. A broken egg must be discarded.
3. The effect of a fall is the same for all eggs.
4. If the egg doesn't break at a certain floor, it will not break at any floor below.
5. If the eggs breaks at a certain floor, it will break at any floor above.

link: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int e, f;
	    cin >> e >> f;
	    int dp[e+1][f+1] = {};
	    
	    // if we are having only one egg then the number of attempts needed 
	    // will be equal to the number of floors
	    for(int i=1; i<=f; i++)
	        dp[1][i] = i;
	    // if we are at the first floor then the maximum attempt needed is 1
	    for(int j=1; j<=e; j++)
	        dp[j][1] = 1;

	    for(int i=2; i<=e; i++) {
	        for(int j=2; j<=f; j++) {
	            dp[i][j] = INT_MAX;
	            int res;
	            
	            // Start from floor one and go till floor j
	            // For each floor take maximum out of the case in which egg breaks and the case in 
	            // which egg doesn't breaks. Assign the best out of all floors.
	            for(int x=1; x<=j; x++) {
	                res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
	                if(res < dp[i][j])
	                    dp[i][j] = res;
	            }
	        }
	    }
	    
	    cout << dp[e][f] << "\n";
	}
	return 0;
}