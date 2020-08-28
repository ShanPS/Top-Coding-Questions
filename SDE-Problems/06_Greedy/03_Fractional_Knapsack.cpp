/*
Problem: Given weights and values of N items, we need to put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack.

Note:
1. Unlike 0/1 knapsack, you are allowed to break the item.
2. Round the answer upto 2 decimal place.

link: https://practice.geeksforgeeks.org/problems/fractional-knapsack/0
*/

#include <bits/stdc++.h>
using namespace std;

struct item {
    float value;
    float weight;
};

bool cmp(item i1, item i2) {
    return (i1.value/i1.weight) > (i2.value/i2.weight);
}

float getMax(item items[], int n, int knapsackCapacity) {
    float totalValue = 0;
    sort(items, items+n, cmp);
    
    for(int i=0; i<n; i++) {
        if(items[i].weight <= knapsackCapacity) {
            totalValue += items[i].value;
            knapsackCapacity -= items[i].weight;
        }
        else {
            totalValue += (items[i].value / items[i].weight) * knapsackCapacity;
            break;
        }
    }
    return totalValue;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, knapsackCapacity;
	    cin >> n >> knapsackCapacity;
	    item items[n];
	    for(int i=0; i<n; i++)
            cin >> items[i].value >> items[i].weight;

        cout << fixed << setprecision(2) << getMax(items, n, knapsackCapacity) << "\n";
	}
	return 0;
}