/*
Problem: Given an array of integers, 
write a function that returns true if there is a triplet (a, b, c) that satisfies a^2 + b^2 = c^2
*/

#include <bits/stdc++.h>
using namespace std;

bool check_for_triplet(int arr[], int n) {
    int maximum = 0;                   // get max value in the array
    for(int i=0; i<n; i++)
        maximum = max(maximum, arr[i]);

    int hash[maximum + 1] = {};        // get frequency of each element
    for(int i=0; i<n; i++)
        hash[arr[i]]++;

    for(int i = 1; i <= maximum; i++) {
        if (hash[i] == 0)              // if no element same as i, then skip
            continue;

        for(int j = 1; j <= maximum; j++) {
            if((i == j && hash[i] == 1) || hash[j] == 0)  // if i==j and freq(i)==1
                continue;                                 // or, if no elements same as j, then skip

            int val = sqrt(i*i + j*j);      // get val as square root of (i^2 + j^2)
            if((val * val) != (i*i + j*j))  // if not perfect square, then skip
                continue;
            if(val > maximum)               // if greater than max value, then skip
                continue;

            if(hash[val])                   // if val is present, then return true
                return true;
        } 
    } 
    return false; 
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
            
        if(check_for_triplet(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
	
	return 0;
}