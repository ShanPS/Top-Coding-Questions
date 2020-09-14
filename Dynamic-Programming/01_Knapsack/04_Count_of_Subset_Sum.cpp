/*
Problem: Given an array arr[] of length N and an integer X, 
the task is to find the number of subsets with sum equal to X.

link: https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
*/

#include <bits/stdc++.h> 
using namespace std; 

int findCount(int arr[], int N, int X) {
    int t[N+1][X+1] = {};

    for(int i=0; i<=N; i++)
        t[i][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=X; j++) {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[N][X];
}