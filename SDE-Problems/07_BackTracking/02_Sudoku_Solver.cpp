/*
Problem: Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row
2. Each of the digits 1-9 must occur exactly once in each column
3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid


Note:
1. Empty cells are indicated by the character '.'
2. The given board contain only digits 1-9 and the character '.'
3. You may assume that the given Sudoku puzzle will have a single unique solution
4. The given board size is always 9x9


link: https://leetcode.com/problems/sudoku-solver/
*/

class Solution {
    bool solved;
    
    bool checkSubSquare(int iMin, int iMax, int jMin, int jMax, char num, vector<vector<char>>& board) {
        for(int i=iMin; i<=iMax; i++)
            for(int j=jMin; j<=jMax; j++)
                if(board[i][j] == num) return true;

        return false;
    }
    
    bool isValid(int row, int col, char num, vector<vector<char>>& board) {
        for(int i=0; i<9; i++) 
            if(board[i][col] == num) return false;
        
        for(int j=0; j<9; j++)
            if(board[row][j] == num) return false;
        
        if(row<3) {
            if(col<3)      { if(checkSubSquare(0, 2, 0, 2, num, board)) return false; } 
            else if(col<6) { if(checkSubSquare(0, 2, 3, 5, num, board)) return false; }
            else           { if(checkSubSquare(0, 2, 6, 8, num, board)) return false; }
        }
        else if(row<6) {
            if(col<3)      { if(checkSubSquare(3, 5, 0, 2, num, board)) return false; }
            else if(col<6) { if(checkSubSquare(3, 5, 3, 5, num, board)) return false; }
            else           { if(checkSubSquare(3, 5, 6, 8, num, board)) return false; }
        }
        else {
            if(col<3)      { if(checkSubSquare(6, 8, 0, 2, num, board)) return false; }
            else if(col<6) { if(checkSubSquare(6, 8, 3, 5, num, board)) return false; }
            else           { if(checkSubSquare(6, 8, 6, 8, num, board)) return false; }
        }
        
        return true;
    }
    
    void solve(int row, int col, vector<vector<char>>& board) {
        if(row == 8 && col == 9) {
            solved = true; return;
        }
        if(col == 9) {
            row++; col = 0;
        }
        
        if(board[row][col] == '.') {
            for(char num='1'; num<='9'; num++) {
                if(isValid(row, col, num, board)) {
                    board[row][col] = num;
                    solve(row, col+1, board);
                    if(solved) return;
                    board[row][col] = '.';
                }  
            }
        }
        else solve(row, col+1, board);
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solved = false;
        solve(0, 0, board);
    }
};