/*
Problem: Given a list of non negative integers, arrange them in such a manner that they form 
the largest number possible.The result is going to be very large, hence return the result in 
the form of a string.
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1+s2 > s2+s1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >>arr[i];
        
        sort(arr, arr+n, cmp);
        string ans = "";
        for(int i=0; i<n; i++)
            ans += to_string(arr[i]);
        
        cout << ans << "\n";
    }
	
	return 0;
}