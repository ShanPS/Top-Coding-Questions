/*
Problem: Given an input stream of n integers, find the kth largest element for each element in the stream.
         If the kth largest element at a particular insertion in the stream doesn't exist print -1.

link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0#
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    priority_queue<int, vector<int>, greater<int>> pq;
	    int k, n, x;
	    cin >> k >> n;
	    
	    for(int i=1; i<=n; i++) {
	        cin >> x;
	        
	        if(i <= k) {
	            pq.push(x);

	            if(i == k) cout << pq.top() << " ";
	            else cout << -1 << " ";
	        }
	        else {
	            if(pq.top() < x) {
	                pq.pop();
	                pq.push(x);
	            }
	            
	            cout << pq.top() << " ";
	        }
	    }

	    cout << "\n";
	}
	return 0;
}