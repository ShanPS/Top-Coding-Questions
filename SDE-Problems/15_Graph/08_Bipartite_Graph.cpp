/*
Problem: Given an adjacency matrix representation of a graph G having 0 based index.
Complete the function isBipartite() which returns true if the graph is a bipartite else returns false.

link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
*/


// returns whether the given graph G (adj matrix representation) is bipartate or not
bool isBipartite(int G[][MAX],int V) {
	// we can check this using graph coloring. the idea is to do coloring of nodes level by level.
	// if any two nodes in adjacent levels have same color then return false.
    vector<int> color (V, 0);
    queue<int> q;
    
    // this for-loop is to check for disconnected graphs as well
    for(int i=0; i<V; i++) {
    	// color[i] == 0, means not yet visited
        if(color[i] == 0) {
            color[i] = 1;
            q.push(i);
        }
        
        // BFS
        while(!q.empty()) {
            int curVertex = q.front(); q.pop();
            
            for(int j=0; j<V; j++) {
                if(G[curVertex][j] == 1) {
                    if(color[j] == 0) {
                        color[j] = 3 - color[curVertex]; // colors are 1 and 2
                        q.push(j);
                    }
                    else if(color[curVertex] == color[j])
                        return false;
                }
            }
        }
    }
    
    return true;
}