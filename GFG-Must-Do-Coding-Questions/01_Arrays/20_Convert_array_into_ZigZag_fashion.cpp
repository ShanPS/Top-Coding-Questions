/*
Problem: Given an array A (distinct elements) of size N. Rearrange the elements of array in 
zig-zag fashion. The converted array should be in form a < b > c < d > e < f. 
The relative order of elements is same in the output i.e you have to iterate on the original array only.
*/

#include <iostream>
using namespace std;

void solve(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        if(i%2 == 0) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        else {
            if(arr[i] < arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        
        cout << arr[i] << " ";
    }
    cout << arr[n-1] << "\n";
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
	        
	    solve(arr, n);
	}
	return 0;
}