/*
Problem: Given an array arr of N positive integers, 
the task is to find the maximum sum increasing subsequence of the given array.

link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
*/

int maxSumIS(int arr[], int n)  {  
    int sum[n], maxSum = INT_MIN;
    
    for(int i=0; i<n; i++)
        sum[i] = arr[i];
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if((arr[i] > arr[j]) && (sum[i] < sum[j] + arr[i]))
                sum[i] = sum[j] + arr[i];
        }
    }
    
    for(int i=0; i<n; i++)
        maxSum = max(maxSum, sum[i]);
    
    return maxSum;
}