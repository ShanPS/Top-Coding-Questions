/*
Problem: Given a directed graph. The task is to do Breadth First Search of this graph.

link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

vector<int> bfs(vector<int> g[], int N) {
    vector<int> vv;
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        vv.push_back(v);
        for(auto vert : g[v]) {
            if(!visited[vert]) {
                q.push(vert);
                visited[vert] = true;
            }
        }
    }
    
    return vv;
}