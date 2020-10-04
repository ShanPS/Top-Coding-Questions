/*
Problem: Given weights and values of n items, put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
*/

#include <bits/stdc++.h>
using namespace std;

int binaryKnapsack(int v[], int wt[], int W, int n) {
    int t[n+1][W+1] = {};
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(wt[i-1] <= j)
                t[i][j] = max(v[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][W];
}

int main() {
	int t;
	cin >> t;

	while(t--) {
	    int n, W;
	    cin >> n >> W;
	    int v[n], wt[n];
	    for(int i=0; i<n; i++) cin >> v[i];
	    for(int i=0; i<n; i++) cin >> wt[i];
	    
	    cout << binaryKnapsack(v, wt, W, n) << "\n";
	}
	
	return 0;
}