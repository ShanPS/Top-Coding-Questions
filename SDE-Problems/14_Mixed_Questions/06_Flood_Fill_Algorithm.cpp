/*
Problem: Given a 2D screen (grid), location of a pixel in the screen (x,y) and a color (K).
Your task is to replace color of the given pixel and all the same colored adjacent pixels 
(excluding diagonally adjacent pixels) with the given color K.


Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0#
*/

#include <bits/stdc++.h>
using namespace std;

void flood_fill(vector<vector<int>>& grid, int r, int c, int x, int y, int new_color) {
    int old_color = grid[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()) {
        int x_cor = q.front().first;
        int y_cor = q.front().second;
        q.pop();
        
        grid[x_cor][y_cor] = new_color;
        
        if(x_cor-1 >= 0 && grid[x_cor-1][y_cor] == old_color) 
            q.push({x_cor-1, y_cor});
        if(y_cor-1 >= 0 && grid[x_cor][y_cor-1] == old_color) 
            q.push({x_cor, y_cor-1});
        if(x_cor+1 < r && grid[x_cor+1][y_cor] == old_color) 
            q.push({x_cor+1, y_cor});
        if(y_cor+1 < c && grid[x_cor][y_cor+1] == old_color) 
            q.push({x_cor, y_cor+1});
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int r, c;
	    int x, y, new_color;
	    
	    cin >> r >> c;
	    vector<vector<int>> grid(r, vector<int>(c, 0));
	    for(int i=0; i<r; i++)
	        for(int j=0; j<c; j++)
	            cin >> grid[i][j];
	    cin >> x >> y >> new_color;
	    
	    flood_fill(grid, r, c, x, y, new_color);
	    
	    for(int i=0; i<r; i++)
	        for(int j=0; j<c; j++)
	            cout << grid[i][j] << " ";
	    
        cout << "\n";
	}
	return 0;
}