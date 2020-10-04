/*
Problem: Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of 
dimension p[i-1] x p[i].

We need to write a function that should return the minimum number of multiplications needed to 
multiply the chain.
*/

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;


int MatrixChain(int d[], int n) {
	int m[n][n];             // extra row and column is for simplicity (row-0 and col-0 won't be used)
	memset(m, 0, sizeof(m)); // set all values to zero

    for(int chain_len=1; chain_len < n-1; chain_len++) {   // start filling in diagonal manner
        for(int i=1; i < n-chain_len; i++) {
            int j = i+chain_len;
            m[i][j] = INT_MAX;
            for(int k=i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j];
                m[i][j] = min(q, m[i][j]);
            }
        }
    }

	return m[1][n-1];
}

int main() {
	// dimensions of matrices are given
	int dims[] = {5, 4, 6, 2, 7};      // matrix Ai has dimension dims[i-1] x dims[i] for i=1 to n
	int size = sizeof(dims)/sizeof(dims[0]);

	cout << "Minimum number of multiplications required is " << MatrixChain(dims, size) << "\n";

    return 0;
}