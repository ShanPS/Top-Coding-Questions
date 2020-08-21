/*
Problem: The cost of stock on each day is given in an array A[] of size N.
Find all the days on which you buy and sell the stock so that in between those days 
your profit is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

void buy_sell(int arr[], int n) {
	bool noprofit = true;
    int start = 0, end = 0;
    int price = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > price) {
            end++;
            price = arr[i];
        }
        else {
            if(start != end) {
                cout << "(" << start << " " << end << ") ";
                noprofit = false;
            }
            price = arr[i];
            start = i;
            end = i;
        }
    }
    
    if(start != end)
        cout << "(" << start << " " << end << ")";
    
    else if(noprofit)
        cout << "No Profit";
        
    cout << "\n";
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
        
        buy_sell(arr, n);
    }    
	return 0;
}