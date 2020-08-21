/*
Problem: Given a sorted array of positive integers.
Your task is to rearrange  the array elements alternatively i.e first element should be max value, 
second should be min value, third should be second max, fourth should be second min and so on...

Note:- O(1) extra space is allowed. Also, try to modify the input array as required.
*/

#include <bits/stdc++.h>
using namespace std;

void rearrange(long long arr[], int n) {
	int min_idx = 0, max_idx = n-1;
    int max_val = arr[n-1]+1;

    for(int i=0; i<n; i++) {
        if(i%2 == 0) {
            arr[i] += (arr[max_idx]%max_val) * max_val;
            max_idx--;
        }
        else {
            arr[i] += (arr[min_idx]%max_val) * max_val;
            min_idx++;
        }
    }

    for(int i=0; i<n; i++)
        arr[i] = arr[i]/max_val;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
        int n;
	    cin >> n;
	    long long arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    
	    rearrange(arr, n);
	    
        for(int i=0; i<n; i++)
	        cout << arr[i] << " ";
	    cout << "\n";
	}
	return 0;
}