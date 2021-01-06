/*
Problem: Given a Directed Graph. Check whether it contains any cycle or not.

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/


// dfs for checking cycle
void dfs(int vertex, vector<int> graph[], vector<bool>& visited, bool& cycle) {
    // if we are at a vertex which is already visited that means cycle is present
    if(visited[vertex]) {
        cycle = true;  // make cycle flag true and return
        return;
    }

    visited[vertex] = true;  // mark the vertex visited
    for(int v : graph[vertex]) {
        dfs(v, graph, visited, cycle);
        
        if(cycle) return;  // if cycle found then no need to do more traversal; return
    }
    visited[vertex] = false;  // mark the vertex unvisited
}

// Function to check whether a cycle is present or not in the given graph (adjacency list)
// V is the number of vertices (numbered from 0 till V-1)
bool isCyclic(int V, vector<int> graph[]) {
    vector<bool> visited (V, false);
    bool cycle = false;
    
    for(int i=0; i<V; i++) {
        dfs(i, graph, visited, cycle);
        
        if(cycle) return true;  // if cycle found then return true
    }
   
    return false;  // if no cycle found in any dfs then return false (ie, no cycle in the graph)
}