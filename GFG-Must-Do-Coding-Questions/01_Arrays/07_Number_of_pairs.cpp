/*
Problem: Given two arrays X and Y of positive integers, 
find number of pairs such that (x^y) > (y^x) where x is an element from X and y is an element from Y.
*/

#include <bits/stdc++.h>
using namespace std;

long long getPairCount(int X[], int Y[], int m, int n) {
	sort(Y, Y+n);
    int ones = upper_bound(Y, Y+n, 1) - Y;                       // get number of ones
    int twos = upper_bound(Y, Y+n, 2) - lower_bound(Y, Y+n, 2);  // get number of twos
    long long count = 0;
    for(int i=0; i<m; i++) {
        if(X[i] == 1)       // if x==1 then there won't be any y matching the condition
            continue;
        else if(X[i] == 2)  // if x==2 then all y greater than 4 will match the required condition
            count += ((Y+n) - upper_bound(Y, Y+n, 4));
        else         // for all other x values, y greater than x will match the required condition
            count += ((Y+n) - upper_bound(Y, Y+n, X[i]));
       
        if(X[i] == 3) count += twos;  // special case
        count += ones;
    }

    return count;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    int X[m], Y[n];
	    for(int i=0; i<m; i++)
	        cin >> X[i];
	    for(int i=0; i<n; i++)
	        cin >> Y[i];
	    
	    cout << getPairCount(X, Y, m, n) << "\n";
	}
	return 0;
}