/*
Problem: You are given values and weights of N items, put these items in a knapsack of capacity W to 
get the maximum total value in the knapsack. 
Note that we have only one quantity of each item and we should either take it or leave it  completely.

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