/*
Problem: You are given a perfect binary tree where all leaves are on the same level, and 
every parent has two children. The binary tree has the following definition:
  struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
  }
Populate each next pointer to point to its next right node. If there is no next right node, 
then the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
1. You may only use constant extra space.
2. Recursive approach is fine, you may assume implicit stack space does not count as extra space.

link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

class Solution {
    void setNext(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        root->left->next = root->right;
        if(root->next != NULL)
            root->right->next = root->next->left;
        
        setNext(root->left);
        setNext(root->right);
    }
    
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        setNext(root);
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/