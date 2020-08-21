/*
Problem: Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai 
where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
*/

#include <bits/stdc++.h>
using namespace std;

int get_storage(int arr[], int n) {
	int storage[n] = {};
    int tall = arr[0];
    for(int i=1; i<n-1; i++) {
        if(arr[i] <= tall)
            storage[i] = tall - arr[i];
        else
            tall = arr[i];
    }
    tall = arr[n-1];
    for(int i=n-2; i>0; i--) {
        if(arr[i] <= tall)
            storage[i] = min(storage[i], tall-arr[i]);
        else {
            tall = arr[i];
            storage[i] = 0;
        }
    }
    
    int totalStorage = 0;
    for(int i=0; i<n; i++)
        totalStorage += storage[i];

    return totalStorage;
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
        
        cout << get_storage(arr, n) << "\n";
    }
	
	return 0;
}