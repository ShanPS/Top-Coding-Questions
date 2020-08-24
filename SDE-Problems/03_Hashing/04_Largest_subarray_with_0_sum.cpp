/*
Problem: Given an array having both positive and negative integers.
The task is to compute the length of the largest subarray with sum 0.

link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n) {
    unordered_map<int, int> m;
    int longest = 0, sum = 0;
    
    m[sum] = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(m.find(sum) != m.end())
            longest = max(longest, i+1-m[sum]);
        else
            m[sum] = i+1;
    }

    return longest;
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
        cout << maxLen(arr, n) << "\n";
    }
}