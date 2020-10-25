/*
Problem: Given a NxN matrix of positive integers.

There are only three possible moves from a cell Matrix[r][c].
1. Matrix [r+1][c]
2. Matrix [r+1][c-1]
3. Matrix [r+1][c+1]
Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

link: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
*/

int maximumPath(int N, vector<vector<int>> Matrix) {
    int sum = 0;
    
    for(int row=1; row<N; row++) {
        for(int col=0; col<N; col++) {
            if(col == 0)
                Matrix[row][col] += max(Matrix[row-1][col], Matrix[row-1][col+1]);
            else if(col == N-1)
                Matrix[row][col] += max(Matrix[row-1][col], Matrix[row-1][col-1]);
            else
                Matrix[row][col] += max(Matrix[row-1][col], max(Matrix[row-1][col-1], Matrix[row-1][col+1]));
        }
    }
    
    for(int col=0; col<N; col++)
        sum = max(sum, Matrix[N-1][col]);
    
    return sum;
}