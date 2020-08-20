/*
Problem: Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S.
*/

#include <bits/stdc++.h>
using namespace std;

void find_subarray(long long arr[], int n, long long s) {
    long long sum = 0;
    int start=0, end=-1;
    bool found = false;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
        end++;
        
        if(sum == s) {
            found = true;
            cout << start+1 << " " << end+1 << "\n";
        }
        
        while(sum > s) {
            sum -= arr[start];
            start++;
            if(sum == s) {
                found = true;
                cout << start+1 << " " << end+1 << "\n";
            }
        }
        
        if(found)
            break;
    }
    
    if(!found)
        cout << -1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long s;
        cin >> n;
        cin >> s;

        long long arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];

        if(s < 0) {
            cout << -1 << "\n";
            continue;
        }
        
        find_subarray(arr, n, s);
    }
    return 0;
}