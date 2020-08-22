/*
Problem: Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

link: https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> pTriangle;
		for(int i=0; i<numRows; i++) {
			vector<int> v(i+1, 1);

			if(i == 0) {
				pTriangle.push_back(v);
			}
			else {
				for(int j=1; j<i; j++)
					v[j] = pTriangle[i-1][j-1] + pTriangle[i-1][j];
				pTriangle.push_back(v);
			}
		}
		return pTriangle;
	}
};