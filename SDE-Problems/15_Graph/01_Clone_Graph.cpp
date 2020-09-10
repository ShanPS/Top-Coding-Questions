/*
Problem: Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a val (int) and a list (vector<Node*>) of its neighbors.

link: https://leetcode.com/problems/clone-graph/
*/

class Solution {
    unordered_set<Node*> visited;
    unordered_map<Node*, Node*> clones;
    queue<Node*> q;
    
    Node* cloneByBFS(Node* node) {
        Node* cloneHead = new Node(node->val);
        clones[node] = cloneHead;
        q.push(node);
        visited.insert(node);
        
        while(!q.empty()) {
            node = q.front();
            q.pop();
            
            Node* clone = clones[node];
            for(Node* n : node->neighbors) {
                if(clones.find(n) != clones.end()) {
                    clone->neighbors.push_back(clones[n]);
                }
                else {
                    Node* temp = new Node(n->val);
                    clone->neighbors.push_back(temp);
                    clones[n] = temp;
                }
                
                if(visited.find(n) == visited.end()) {
                    q.push(n);
                    visited.insert(n);
                }
            }
        }
        
        return cloneHead;
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        visited.clear();
        clones.clear();
        
        return cloneByBFS(node);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/