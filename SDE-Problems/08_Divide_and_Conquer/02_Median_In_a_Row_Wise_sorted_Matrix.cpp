/*
Problem: We are given a row wise sorted matrix of size r*c.
We need to find the median of the matrix given. It is assumed that r*c is always odd.

link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix/0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		// take inputs
	    int r, c;
	    cin >> r >> c;
	    int arr[r][c];
	    for(int i=0; i<r; i++)
	        for(int j=0; j<c; j++)
	            cin >> arr[i][j];
	    
	    // get the minimum and maximum number in the matrix
	    int minNum=INT_MAX, maxNum=INT_MIN;
	    for(int i=0; i<r; i++) {
	        minNum = min(minNum, arr[i][0]);
	        maxNum = max(maxNum, arr[i][c-1]);
	    }
	    while(minNum < maxNum) {
	        int mid = minNum + (maxNum-minNum)/2;  // take the average of min and max elements as mid
	        
	        // get count of numbers less than or equal to mid
	        int count = 0;
	        for(int i=0; i<r; i++)
	            count += upper_bound(arr[i], arr[i]+c, mid) - arr[i];
	        
	        // update the number range accordingly
	        if(count <= (r*c)/2) minNum = mid+1;
	        else maxNum = mid;
	    }
	    
	    cout << minNum << "\n";
	}
	return 0;
}