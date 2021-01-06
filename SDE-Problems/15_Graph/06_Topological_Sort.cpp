/*
Problem: Given a Directed Graph. Find any Topological Sorting of that Graph.

Note:
1. Graph doesn't contain multiple edges, self loops and cycles.
2. Graph may be disconnected.

link: https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/


// dfs function to help in doing the topoSort
void dfs(int vertex, vector<int> graph[], vector<bool>& visited, vector<int>& answer) {
    visited[vertex] = true;  // make vertex visited

    // do dfs for adjacent vertices if they are not already visited
    for(int v : graph[vertex]) {
        if(!visited[v]) dfs(v, graph, visited, answer);
    }

    // once all other nodes that can be reached from the current vertex is visited
    // then push the current vertex into answer list
    answer.push_back(vertex);
}


// Function to do topological sorting of the given directed graph (adjacency list representation)
// V is the number of vertices (ranging from 0 to V-1)
vector<int> topoSort(int V, vector<int> graph[]) {
    static vector<int> answer;
    vector<bool> visited (V, false);  // to keep track of visited vertices
    
    for(int i=0; i<V; i++) {
        if(!visited[i])  // if not yet visited then do dfs from there
            dfs(i, graph, visited, answer);
    }
    
    // reverse the order of the answer
    // (so that nodes which doesnot depend on any other nodes will come first)
    reverse(answer.begin(), answer.end());
    return answer;
}