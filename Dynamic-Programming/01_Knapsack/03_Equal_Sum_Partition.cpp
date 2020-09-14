/*
Problem: Given an array arr[] of size N, check if it can be partitioned into two parts such that 
the sum of elements in both parts is the same.

link: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
*/

int equalPartition(int N, int arr[]) {
    int sum = 0;
    for(int i=0; i<N; i++) sum += arr[i];
    
    if(sum%2 == 1) return 0;
    
    sum = sum / 2;
    bool t[N+1][sum+1];
	for(int i=0; i<=N; i++) t[i][0] = true;
	for(int j=1; j<=sum; j++) t[0][j] = false;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=sum; j++) {
			if(arr[i-1] <= j)
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	return t[N][sum];
}