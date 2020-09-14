/*
Problem: Given an array arr[] of size N and an integer K, check if it there exits a subset in arr 
such that the sum of subset is equal to K.
*/

bool subsetSum(int arr[], int N, int K) {
	bool t[N+1][K+1];
	for(int i=0; i<=N; i++) t[i][0] = true;
	for(int j=1; j<=K; j++) t[0][j] = false;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=K; j++) {
			if(arr[i-1] <= j) {
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			}
			else {
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[N][K];
}