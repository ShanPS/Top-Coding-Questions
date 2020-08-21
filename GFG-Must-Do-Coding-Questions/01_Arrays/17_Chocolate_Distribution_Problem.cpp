/*
Problem: Given an array A of positive integers of size N, where each value represents number of 
chocolates in a packet. Each packet can have variable number of chocolates. There are M students, 
the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum 
chocolates and student having packet with minimum chocolates is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int m;
        cin >> m;
        
        sort(arr, arr+n);
        
        long long diff = LLONG_MAX;
        for(int i=m-1; i<n; i++)
            diff = min(diff, arr[i]-arr[i-m+1]);
        
        cout << diff << "\n";
    }
	return 0;
}