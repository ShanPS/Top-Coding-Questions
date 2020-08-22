/*
Problem: Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m.
The task is to merge the two sorted arrays in such a way that all smaller elements will be in 
arr1[] and larger will be in arr2[] (in non-decreasing order).

Note:
1. Expected time complexity : O((n+m) log(n+m))
2. Do not use extra space

link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int m, int n) {
    int gap = (m + n + 1) / 2;    // initially gap will be half the size (ceil) of total elements
    
    // recursively reduce the gap as (gap+1)/2
    while(true) {
    	// two pointers (indices), differs by gap.
    	// will run from start till end.
        int i = 0, j = gap;

        // first case --> both element in arr1[]
        while(j < m) {
            if(arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);
            i++; j++;
        }
        // second case --> one element in arr1[] and the other in arr2[]
        while(i < m && j < m+n) {
            if(arr1[i] > arr2[j-m])
                swap(arr1[i], arr2[j-m]);
            i++; j++;
        }
        // third case --> both element in arr2[]
        while(j < m+n) {
            if(arr2[i-m] > arr2[j-m])
                swap(arr2[i-m], arr2[j-m]);
            i++; j++;
        }

        if(gap == 1) break;  // if the gap is already 1 then stop
        gap = (gap+1)/2;     // else reduce the gap as (gap+1)/2 and continue
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    int arr1[m], arr2[n];
	    for(int i=0; i<m; i++) cin >> arr1[i];
	    for(int i=0; i<n; i++) cin >> arr2[i];
	    
	    merge(arr1, arr2, m, n);
	    
	    for(int i=0; i<m; i++) cout << arr1[i] << " ";
	    for(int i=0; i<n; i++) cout << arr2[i] << " ";
	    cout << "\n";
	}
	return 0;
}