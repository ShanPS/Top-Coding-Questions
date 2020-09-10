/*
Problem: Given a connected undirected graph. Perform a Depth First Traversal of the graph.

link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void doDFS(int vertex, vector<int> g[], vector<int>& vv, vector<bool>& visited) {
    vv.push_back(vertex);
    visited[vertex] = true;
    
    for(auto vert : g[vertex]) {
        if(!visited[vert]) doDFS(vert, g, vv, visited);
    }
}

vector<int> dfs(vector<int> g[], int N)
{
    vector<int> vv;
    vector<bool> visited(N, false);
    doDFS(0, g, vv, visited);
    return vv;
}