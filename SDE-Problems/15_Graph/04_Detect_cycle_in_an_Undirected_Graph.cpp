/*
Problem: Given an Undirected Graph. Check whether it contains a cycle or not. 

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
*/


// dfs for checking cycle
void dfs(int vertex, int parent, vector<int> graph[], vector<bool>& visited, bool& cycle) {
    // if we are at a vertex which is already visited that means cycle is present
    if(visited[vertex]) {
        cycle = true;  // make cycle flag true and return
        return;
    }
    visited[vertex] = true;  // mark the vertex visited
    
    for(int v : graph[vertex]) {
        if(v != parent)
            dfs(v, vertex, graph, visited, cycle);
        
        if(cycle) return;  // if cycle found then no need to do more traversal; return
    }
}

// Function to check whether a cycle is present or not in the given graph (adjacency list)
// V is the number of vertices (numbered from 0 till V-1)
bool isCyclic(vector<int> graph[], int V) {
    vector<bool> visited (V, false);
    bool cycle = false;
    
    // checking for all vertices (in case of graph not being fully connected)
    for(int i=0; i<V; i++) {
        if(!visited[i]) 
            dfs(i, -1, graph, visited, cycle);
        
        if(cycle) return true; // if cycle found then return true
    }
   
    return false;  // if no cycle found in any dfs then return false (ie, no cycle in the graph)
}