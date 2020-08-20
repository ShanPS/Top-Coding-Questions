/*
Problem: Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++) 
	        cin >> arr[i];

	    int sum = 0, best = INT_MIN;
	    for(int i=0; i<n; i++) {
	        sum += arr[i];
	        best = max(best, sum);
	        if(sum<0)
	            sum = 0;
	    }
	    
	    cout << best << endl;
	}
	return 0;
}