/*
Problem: Given a positive integer N, 
print its corresponding column title as it would appear in an Excel sheet.
Eg: for N =1 we have column A, for 27 we have AA and so on.

Note: 
1. The alphabets are all in uppercase.

link: https://practice.geeksforgeeks.org/problems/excel-sheet/0
*/

#include <bits/stdc++.h>
using namespace std;

string numberToTitle(int n) {
    string s;
    
    while(n) {
        int d = n%26;
        if(d == 0) {
            s += 'Z';
            n--;
        }
        else {
            s += (char)('A' + d - 1);
        }
        
        n = n/26;
    }
    
    reverse(s.begin(), s.end());
    return s;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    cout << numberToTitle(n) << "\n";
	}
	return 0;
}