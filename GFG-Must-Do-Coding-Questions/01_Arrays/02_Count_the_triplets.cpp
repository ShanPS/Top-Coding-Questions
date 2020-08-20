/* 
Problem: Given an array of distinct integers. 
The task is to count all the triplets such that sum of two elements equals the third element.
*/

#include <bits/stdc++.h>
using namespace std;

int count_triplets(int arr[], int n) {
    int count = 0;

    for(int i=n-1; i>=2; i--) {
        int left = 0, right = i-1;
        int sum;

        while(left<right) {
            sum = arr[left] + arr[right];
            if(sum == arr[i]) {
                count++;
                left++; right--;
            }
            else if(sum < arr[i])
                left++;
            else
                right--;
        }
    }
    
    return (count == 0) ? -1 : count;
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
        
        sort(arr, arr+n);
        cout << count_triplets(arr, n) << "\n";
    }
	return 0;
}