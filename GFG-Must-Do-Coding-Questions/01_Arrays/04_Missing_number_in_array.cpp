/*
Problem: Given an array C of size N-1 and given that there are numbers from 1 to N with one 
element missing, the missing number is to be found.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int arr[n-1];
        for(int i=0; i<n-1; i++)
            cin >> arr[i];
        
        long long sum = 0;
        for(int i=0; i<n-1; i++)
            sum += arr[i];
        
        cout << ((n * (long long)(n+1))/2) - sum << "\n";
    }
    
	return 0;
}