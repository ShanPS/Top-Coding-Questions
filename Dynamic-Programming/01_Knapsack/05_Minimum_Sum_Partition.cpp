/*
Problem: Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that 
the absolute difference between their sums is minimum and find the minimum difference.

link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
*/

int minDiffernce(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    
    bool t[n+1][sum+1];
    for(int i=0; i<=n; i++) t[i][0] = true;
    for(int j=1; j<=sum; j++) t[0][j] = false;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    int diff = INT_MAX;
    for(int j=sum/2; j>=0; j--) {
        if(t[n][j]) {
            diff = sum - 2*j;
            break;
        }
    }
    
    return diff;
}