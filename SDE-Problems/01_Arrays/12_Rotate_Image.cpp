/*
Problem: You are given an NxN 2D matrix representing an image. Rotate the image by 90 degrees (clockwise)

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly

link: https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-i-1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};