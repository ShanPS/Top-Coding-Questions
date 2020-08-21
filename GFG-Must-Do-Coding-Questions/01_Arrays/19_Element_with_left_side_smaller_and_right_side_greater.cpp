/*
Problem: Given an unsorted array of size N. Find the first element in array such that all of 
its left elements are smaller and all right elements to it are greater than it.
*/

#include <bits/stdc++.h>
using namespace std;

int find_ele(int arr[], int n) {
	int left[n]= {};
    int right[n] = {};
    int maxval = arr[0], minval = arr[n-1];
    for(int i = 1; i < n; i++) {
        maxval = max(maxval, arr[i]);
        left[i] = maxval;
    }
    for(int i = n-2; i >= 0; i--) {
        minval = min(minval, arr[i]);
        right[i] = minval;
    }
    
    bool found = false;
    for(int i = 1; i < n-1; i++) {
        if(left[i] <= arr[i] && arr[i] <= right[i]) {
            found = true;
            cout << arr[i] << "\n";
            break;
        }
    }
    if(!found)
        cout << -1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        ind_ele(arr, n);        
    }
	return 0;
}