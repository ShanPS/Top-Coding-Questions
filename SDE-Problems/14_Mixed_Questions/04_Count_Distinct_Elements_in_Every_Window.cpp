/*
Problem: Given an array of integers and a number K. 
Find the count of distinct elements in every window of size K in the array.

Link: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#
*/

vector<int> countDistinct (int A[], int n, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    int count = 0;
    
    for(int i=0; i<k && i<n; i++) {
        if(mp[A[i]] == 0) count++;
        
        mp[A[i]]++;
    }
    ans.push_back(count);
    
    for(int i=k; i<n; i++) {
        mp[A[i-k]]--;
        
        if(mp[A[i-k]] == 0) count--;
        if(mp[A[i]] == 0) count++;
        
        mp[A[i]]++;
        
        ans.push_back(count);
    }
    
    return ans;
}