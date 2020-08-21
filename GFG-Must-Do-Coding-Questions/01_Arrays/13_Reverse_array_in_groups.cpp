/*
Problem: Given an array arr[] of positive integers of size N. 
Reverse every sub-array of K group elements.
*/

#include <bits/stdc++.h>
using namespace std;

void reverse_in_group(int arr[], int n, int k) {
	int start = 0;
    int end;
    while(start < n) {
        end = min(n, start+k);
        reverse(arr+start, arr+end);
        start += k;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        reverse_in_group(arr, n, k);
        
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    
	return 0;
}