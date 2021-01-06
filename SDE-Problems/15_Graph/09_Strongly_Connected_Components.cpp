/*
Problem: Given a directed graph. Your task is to complete the function kosaraju() which returns 
an integer denoting the number of strongly connected components in the graph.

link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
*/


// Function for doing DFS. Helps kosaraju() function.
void DFS(int vertex, vector<int> graph[], stack<int>& stk, vector<bool>& visited, bool reversed = false) {
    visited[vertex] = true;
    
    for(int v : graph[vertex]) {
        if(!visited[v])
            DFS(v, graph, stk, visited, reversed);
    }
    
    if(!reversed)
	    stk.push(vertex);
}

// Function to return the number of Strongly Connected Components using Kosaraju's Algorithm
int kosaraju(int V, vector<int> graph[]) {
    stack<int> stk;
    vector<bool> visited(V, false);
    int numSCC = 0;
    
    for(int vertex=0; vertex<V; vertex++) {
        if(!visited[vertex]) 
            DFS(vertex, graph, stk, visited);
    }
    
    visited = vector<bool>(V, false);
    vector<int> revGraph[V];
    for(int vertex=0; vertex<V; vertex++) {
        for(int v : graph[vertex])
            revGraph[v].push_back(vertex);
    }
    
    while(!stk.empty()) {
        int vertex = stk.top(); stk.pop();
        
        if(!visited[vertex]) {
            DFS(vertex, revGraph, stk, visited, true);
            numSCC++;
        }
    }
    
    return numSCC;
}