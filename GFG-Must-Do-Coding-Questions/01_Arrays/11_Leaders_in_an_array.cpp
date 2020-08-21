/*
Problem: Given an array of positive integers. Your task is to find the leaders in the array.

Note:- An element of array is leader if it is greater than or equal to all the elements to its 
right side. Also, the rightmost element is always a leader. 
*/

#include <iostream>
#include <stack>
using namespace std;

void find_leaders(int arr[], int n) {
	int high = -1e8;
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        if(arr[i]>=high) {
            high = arr[i];
            s.push(arr[i]);
        }
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout <<"\n";
}

int main() {
	int t, n;;
	cin >> t;
	while(t--) {
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    
	    find_leaders(arr, n);
	}
	return 0;
}