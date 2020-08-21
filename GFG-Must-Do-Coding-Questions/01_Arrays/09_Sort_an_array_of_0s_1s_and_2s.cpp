/*
Problem: Given an array A of size N containing 0s, 1s, and 2s; 
you need to sort the array in ascending order.
*/

#include <iostream>
using namespace std;

void sort_array(int arr[], int n) {
	int low = 0, high = n-1;
    int idx = 0;
    while(idx <= high) {
        if(arr[idx] == 0) {
            swap(arr[idx], arr[low]);
            low++;
            idx++;
        }
        else if(arr[idx] == 1) {
            idx++;
        }
        else {
            swap(arr[idx], arr[high]);
            high--;
        }
    }
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
	    
	    sort_array(arr, n);
	    
	    for(int i=0; i<n; i++)
	        cout << arr[i] << " ";
	    cout << "\n";
	}
	return 0;
}