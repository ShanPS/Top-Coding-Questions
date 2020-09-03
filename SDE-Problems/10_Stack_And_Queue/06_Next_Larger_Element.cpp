/*
Problem: Given an array A of size N having distinct elements, the task is to find the next 
greater element for each element of the array in order of their appearance in the array. 
If no such element exists, output -1 

link: https://practice.geeksforgeeks.org/problems/next-larger-element/0
*/

#include <bits/stdc++.h>
using namespace std;

void nextLarger(int arr[], int n) {
    long long ans[n];
    stack<long long> s;
    
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && arr[i] >= s.top())
            s.pop();
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    long long arr[n];
	    for(int i=0; i<n; i++)
            cin >> arr[i];
	    
	    nextLarger(arr, n);
	}
	return 0;
}