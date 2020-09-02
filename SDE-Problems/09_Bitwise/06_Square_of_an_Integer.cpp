/*
Problem: Given an integer n, calculate square of a number without using *, / and pow()

link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
*/

#include<iostream>
using namespace std;

long long square(int n) {
	long long sq = 0;
	long long num = abs((long long) n);

	for(int i=31; i>=0; i--) {
		if(num & (1 << i)) {
			sq += (num << i);
		}
	}

	return sq;
}

int main() {
	int n;
	cin >> n;

	cout << square(n) << "\n";
	return 0;
}
