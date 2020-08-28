/*
Problem: There are N piles of coins each containing  'Ai' (1<=i<=N) coins.
Now, you have to adjust the number of coins in each pile such that for any two pile, if 'a' be the 
number of coins in first pile and 'b' is the number of coins in second pile then |a-b|<=K. 
In order to do that you can remove coins from different piles to decrease the number of coins 
in those piles but you cannot increase the number of coins in a pile by adding more coins.
Now, given a value of N and K, along with the sizes of the N different piles you have to tell 
the minimum number of coins to be removed in order to satisfy the given condition.

Note:
You can also remove a pile from consideration by removing all the coins of that pile.

link: https://practice.geeksforgeeks.org/problems/coin-piles/0
*/

#include <bits/stdc++.h>
using namespace std;

int coinPiles(int arr[], int n, int k) {
    int sum[n] = {};
    int count, ans = INT_MAX;
    
    sort(arr, arr+n);
    sum[0] = arr[0];
    for(int i=1; i<n; i++)
        sum[i] = sum[i-1] + arr[i];
    
    for(int i=0; i<n; i++) {
        count = 0;
        // remove all piles to the left of the current pile
        if(i>0) count += sum[i-1];
        
        // get number of elements less than or equals arr[i]+k 
        int num = upper_bound(arr+i+1, arr+n, arr[i]+k) - arr;
        
        if(num < n) // if there is some element greater than arr[i]+k
            count += ((sum[n-1]-sum[num-1]) - (n-num)*(arr[i]+k));
        ans = min(ans, count);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	   
	    cout << coinPiles(arr, n, k) << "\n";
	}
	return 0;
}