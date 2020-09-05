/*
Problem: In a given grid, each cell can have one of three values:
    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is 
impossible, return -1 instead.

link: https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> dq;
        int fresh_oranges = 0, rotten_oranges = 0, minutes = 0;
        int r = grid.size(), c = grid[0].size();
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    fresh_oranges++;
                }
                else if(grid[i][j] == 2) {
                    dq.push_front({i, j});
                    rotten_oranges++;
                }
            }
        }
        
        if(fresh_oranges == 0) return 0;
            
        int total_oranges = fresh_oranges + rotten_oranges;
        while(!dq.empty()) {
            int cur_rot_oranges = dq.size();
            bool has_rotted = false;
            
            while(cur_rot_oranges--) {
                pair<int,int> cur_cell = dq.front();
                dq.pop_front();
                int cur_r = cur_cell.first;
                int cur_c = cur_cell.second;
                
                // Top
                if(cur_r - 1 >= 0 && grid[cur_r - 1][cur_c] == 1) {
                    grid[cur_r -1][cur_c] = 2;
                    dq.push_back({cur_r - 1, cur_c});
                    has_rotted = true;
                    rotten_oranges++;
                }
                
                // Right
                if(cur_c + 1 < c && grid[cur_r][cur_c + 1] == 1) {
                    grid[cur_r][cur_c + 1] = 2;
                    dq.push_back({cur_r, cur_c + 1});
                    has_rotted = true;
                    rotten_oranges++;
                }
                
                // Bottom
                if(cur_r + 1 < r && grid[cur_r + 1][cur_c] == 1) {
                    grid[cur_r + 1][cur_c] = 2;
                    dq.push_back({cur_r + 1, cur_c});
                    has_rotted = true;
                    rotten_oranges++;
                }
                
                // Left
                if(cur_c - 1 >= 0 && grid[cur_r][cur_c - 1] == 1) {
                    grid[cur_r][cur_c - 1] = 2;
                    dq.push_back({cur_r, cur_c - 1});
                    has_rotted = true;
                    rotten_oranges++;
                }
            }
            
            if(has_rotted)
                minutes++;
        }
        
        if(total_oranges != rotten_oranges) return -1;
        return minutes;
    }
};