/*
Problem: Given an integer N denoting the Length of a line segment. 
you need to cut the line segment in such a way that the cut length of a line segment each time is 
integer either x, y or z. and after performing all cutting operation the total number of cutted 
segments must be maximum. 

link: https://practice.geeksforgeeks.org/problems/cutted-segments/0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, x, y, z;
	    cin >> n >> x >> y >> z;
	    
	    int t[n+1] = {};
	    
	    if(x <= n) t[x] = 1;
	    if(y <= n) t[y] = 1;
	    if(z <= n) t[z] = 1;
	    
	    for(int i=1; i<=n; i++) {
	        if(i > x && t[i-x]) t[i] = max(t[i], 1 + t[i-x]);
	        if(i > y && t[i-y]) t[i] = max(t[i], 1 + t[i-y]);
            if(i > z && t[i-z]) t[i] = max(t[i], 1 + t[i-z]);
	    }
	    
	    cout << t[n] << "\n";
	}
	return 0;
}