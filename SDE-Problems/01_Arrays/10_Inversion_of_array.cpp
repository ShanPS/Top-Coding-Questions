/*
Problem: Given an array of positive integers. The task is to find inversion count of array.
Inversion: Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

link: https://practice.geeksforgeeks.org/problems/inversion-of-array/0
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right, long long & count) {
    int n = right-left+1;
    int temp[n];
    int idx=0, i=left, j=mid+1;
    
    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) {
            temp[idx] = arr[i];
            idx++; i++;
        }
        else {
            temp[idx] = arr[j];
            count += (mid-i+1);
            idx++; j++;
        }
    }
    while(i<=mid) {
        temp[idx] = arr[i];
        idx++; i++;
    }
    while(j<=right) {
        temp[idx] = arr[j];
        idx++; j++;
    }
    
    for(idx=0; idx<n; idx++)
        arr[left+idx] = temp[idx];
}

void mergesort(int arr[], int left, int right, long long& count) {
    if(left == right)
        return;
    
    int mid = left + (right-left)/2;
    mergesort(arr, left, mid, count);
    mergesort(arr, mid+1, right, count);
    merge(arr, left, mid, right, count);
    
    return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    
	    long long count = 0;
	    mergesort(arr, 0, n-1, count);
	    cout << count << "\n";
	}
	return 0;
}