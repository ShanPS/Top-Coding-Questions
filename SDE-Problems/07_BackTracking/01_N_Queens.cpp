/*
Problem: The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that 
no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

link: https://leetcode.com/problems/n-queens/
*/

class Solution {
    bool isOkayToPlaceAt(int row, int col, int n, vector<vector<int>>& boardState) {
        for(int i=0; i<n; i++)
            if(boardState[i][col] == 1) return false;
        for(int j=0; j<n; j++)
            if(boardState[row][j] == 1) return false;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(boardState[i][j] == 1) return false;
        for(int i=row+1, j=col+1; i<n && j<n; i++, j++)
            if(boardState[i][j] == 1) return false;
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--)
            if(boardState[i][j] == 1) return false;
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
            if(boardState[i][j] == 1) return false;
        
        return true;
    }
    
    void solve(int row, int& n, vector<vector<string>>& solutions, vector<vector<int>>& boardState) {
        if(row == n) {
            vector<string> curSolution;
            for(int i=0; i<n; i++) {
                string s;
                for(int j=0; j<n; j++) {
                    if(boardState[i][j] == 0) s += ".";
                    else s += "Q";
                }
                curSolution.push_back(s);
            }
            
            solutions.push_back(curSolution);
            return;
        }
        
        for(int col=0; col<n; col++) {
            if(isOkayToPlaceAt(row, col, n, boardState)) {
                boardState[row][col] = 1;
                solve(row+1, n, solutions, boardState);
                boardState[row][col] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<vector<int>> boardState(n, vector<int>(n, 0));
        
        solve(0, n, solutions, boardState);
        
        return solutions;
    }
};