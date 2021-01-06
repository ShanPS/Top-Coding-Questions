/*
Problem: Given a Matrix consisting of 0s and 1s. 
Find the number of islands of connected 1s present in the matrix.

Note: 
1 is said to be connected if it has another 1 around it (either of the 8 directions). 

link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#
*/


// helps in finding number of islands
void DFS(int i, int j, int& rows, int& cols, vector<int> grid[], vector<vector<bool>>& visited) {
    visited[i][j] = true;
    
    if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==false)
        DFS(i, j-1, rows, cols, grid, visited);
    if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==1 && visited[i-1][j-1]==false)
        DFS(i-1, j-1, rows, cols, grid, visited);
    if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==false)
        DFS(i-1, j, rows, cols, grid, visited);
    if(i-1>=0 && j+1<cols && grid[i-1][j+1]==1 && visited[i-1][j+1]==false)
        DFS(i-1, j+1, rows, cols, grid, visited);
    if(j+1<cols && grid[i][j+1]==1 && visited[i][j+1]==false)
        DFS(i, j+1, rows, cols, grid, visited);
    if(i+1<rows && j+1<cols && grid[i+1][j+1]==1 && visited[i+1][j+1]==false)
        DFS(i+1, j+1, rows, cols, grid, visited);
    if(i+1<rows && grid[i+1][j]==1 && visited[i+1][j]==false)
        DFS(i+1, j, rows, cols, grid, visited);
    if(i+1<rows && j-1>=0 && grid[i+1][j-1]==1 && visited[i+1][j-1]==false)
        DFS(i+1, j-1, rows, cols, grid, visited);
}

// Function to find the number of islands
int findIslands(vector<int> grid[], int rows, int cols) {
    vector<vector<bool>> visited (rows, vector<bool>(cols, false));
    int numIslands = 0;
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(grid[i][j]==1 && visited[i][j]==false) {
                numIslands++;
                DFS(i, j, rows, cols, grid, visited);
            }
        }
    }
    
    return numIslands;
}