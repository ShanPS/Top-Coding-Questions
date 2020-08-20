/*
Problem: Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. 
The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).
Note :- Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    int arr1[m], arr2[n];
	    for(int i=0; i<m; i++)
	        cin >> arr1[i];
	    for(int i=0; i<n; i++)
	        cin >> arr2[i];
	    
	    int idx1 = m-1, idx2 = 0;
	    while(idx1>=0 && idx2 < n) {
	        if(arr1[idx1] > arr2[idx2]) {
	            swap(arr1[idx1], arr2[idx2]);
	            idx1--;
	            idx2++;
	        }
	        else break;
	    }
	    
	    sort(arr1, arr1+m);
	    sort(arr2, arr2+n);
	    
	    for(int i=0; i<m; i++)
	        cout << arr1[i] << " ";
	    for(int i=0; i<n; i++)
	        cout << arr2[i] << " ";
	    cout << "\n";
	}
	return 0;
}