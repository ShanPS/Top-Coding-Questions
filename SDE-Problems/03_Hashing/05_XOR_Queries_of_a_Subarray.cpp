/*
Problem: Given the array 'arr' of positive integers and the array 'queries',
where queries[i] = [Li, Ri]. For each query i compute the XOR of elements from Li to Ri 
(that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri]). 
Return an array containing the result for the given queries. 

link: https://leetcode.com/problems/xor-queries-of-a-subarray/
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors;
        vector<int> ans;
        int n = arr.size(), q = queries.size();
        
        xors.push_back(arr[0]);
        for(int i=1; i<n; i++)
            xors.push_back(arr[i] ^ xors[i-1]);
        
        for(int i=0; i<q; i++) {
            if(queries[i][0] == 0)
                ans.push_back(xors[queries[i][1]]);
            else
                ans.push_back( xors[queries[i][0]-1] ^ xors[queries[i][1]] );
        }
        
        return ans;
    }
};