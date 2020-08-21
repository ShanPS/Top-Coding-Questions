/*
Problem: Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        int arr[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin >> arr[i][j];
        
        int up = 0, left = 0, down = m-1, right = n-1;
        while(up<=down && left<=right) {
            for(int i=left; i<=right; i++)
                cout << arr[up][i] << " ";
            up++;
            
            for(int i=up; i<=down; i++)
                cout << arr[i][right] << " ";
            right--;
            
            if(up<=down) {
                for(int i=right; i>=left; i--)
                    cout << arr[down][i] << " ";
                down--;
            }
            
            if(left<=right) {
                for(int i=down; i>=up; i--)
                    cout << arr[i][left] << " ";
                left++;
            }
        }
        cout << "\n";
    }
	
	return 0;
}