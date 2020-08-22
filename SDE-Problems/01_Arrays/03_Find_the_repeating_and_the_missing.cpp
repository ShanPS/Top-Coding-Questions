/*
Problem: Given an unsorted array of size n. Array elements are in the range from 1 to n. 
One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
Find these two numbers.

link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0
*/

#include <bits/stdc++.h>
using namespace std;

// uses the arr as the hash-map
void missAndRepeat(int arr[], int n) {
    int missing, repeating = INT_MAX;
    
    for(int i=0; i<n; i++) {
        if(arr[abs(arr[i]) - 1] < 0)
            repeating = min(repeating, abs(arr[i]));
        else
            arr[abs(arr[i]) - 1] *= -1;
    }
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            missing = i+1;
            break;
        }
    }
    
    cout << repeating << " " << missing << "\n";
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
    	
    	missAndRepeat(arr, n);
	}
	return 0;
}