/*
Problem: Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Note: 
1. O(mn) space solution is easy
2. Try to get an O(1) space solution

link: https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // we will use first row and first column as flags to indicated whether that entire row or 
        // column should be made zero
        bool columnZero = false; // additional boolean variable to keep track of first column
        for(int i=0; i<rows; i++){
            if(matrix[i][0] == 0) columnZero = true;
            for(int j=1; j<cols; j++){
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=1; j--){
                if((matrix[i][0] == 0) || (matrix[0][j] == 0))
                    matrix[i][j]=0;
            }
            if(columnZero)
                matrix[i][0]=0;
        }
    }
};