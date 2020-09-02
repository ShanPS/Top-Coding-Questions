/*
Problem: Given a number.
find the most significant bit number which is set bit and which is in power of two

link: https://www.geeksforgeeks.org/find-significant-set-bit-number/
*/

#include <iostream>
using namespace std;

int setBitNumber(int n) {
	// Below steps set bits after MSB (including MSB)
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;

	// Increment n by 1 so that there is only one set bit 
	// which is just before original MSB.
	n = n + 1;

	// Return original MSB after shifting.
	return (n >> 1);
}

int main() {
	int n = 273;
	cout << setBitNumber(n);
	return 0;
} 
