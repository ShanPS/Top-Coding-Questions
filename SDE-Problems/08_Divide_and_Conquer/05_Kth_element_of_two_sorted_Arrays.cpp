/*
Problem: Given two sorted arrays A and B of size M and N respectively and an element k. 
The task is to find the element that would be at the k’th position of the final sorted array.

link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(int *arr1, int *arr2, int *end1, int *end2, int k) {
    if(arr1 == end1) return arr2[k];
    if(arr2 == end2) return arr1[k];
    
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if(mid1+mid2 < k) {
        if(arr1[mid1] > arr2[mid2])
            return kthElement(arr1, arr2+mid2+1, end1, end2, k-(mid2+1));
        else
            return kthElement(arr1+mid1+1, arr2, end1, end2, k-(mid1+1));
    }
    else {
        if(arr1[mid1] > arr2[mid2])
            return kthElement(arr1, arr2, arr1+mid1, end2, k);
        else
            return kthElement(arr1, arr2, end1, arr2+mid2, k);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n, k;
	    cin >> m >> n >> k;
	    int a1[m], a2[n];
	    for(int i=0; i<m; i++) cin >> a1[i];
	    for(int i=0; i<n; i++) cin >> a2[i];
	    
	    cout << kthElement(a1, a2, a1+m, a2+n, k-1) << "\n";
	}
	return 0;
}