/*
Problem: Given a string S consisting only '0's and '1's,  
print the last index of the '1' present in it. 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = -1;
        int len = s.size();
        
        for(int i=len-1; i>=0; i--) {
            if(s[i] == '1') {
                ans = i;
                break;
            }
        }
        
        cout << ans << "\n";
    }
	return 0;
}