/*
Problem: You are given a number N.
Find the total count of set bits for all numbers from 1 to N (both inclusive).

link: https://practice.geeksforgeeks.org/problems/count-total-set-bits/0
*/

#include <bits/stdc++.h>
using namespace std;

int getTotalSetBits(int n) {
    int totalSetBits = 0;
    for(int i=1; i<=n; i++) {
        int num = i, count = 1;
        while(num & (num-1)) {
            count++;
            num = num & (num-1);
        }
        totalSetBits += count;
    }
    return totalSetBits;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    cout << getTotalSetBits(n) << "\n";
	}
	return 0;
}