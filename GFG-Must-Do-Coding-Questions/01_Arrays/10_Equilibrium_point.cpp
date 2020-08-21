/*
Problem: Given an array A of N positive numbers. The task is to find the position where equilibrium 
first occurs in the array. Equilibrium position in an array is a position such that the sum of 
elements before it is equal to the sum of elements after it.
*/

#include <bits/stdc++.h>
using namespace std;

void find_equilibrium_point(int arr[], int n) {
	int left[n] = {}, right[n] = {};
    for(int i=1; i<n; i++)
        left[i] = left[i-1] + arr[i-1];
    for(int i=n-2; i>=0; i--)
        right[i] = right[i+1] + arr[i+1];
    
    bool found = false;
    for(int i=0; i<n; i++) {
        if(left[i] == right[i]) {
            cout << i+1 << "\n";
            found = true;
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
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        find_equilibrium_point(arr, n);
    }
	
	return 0;
}