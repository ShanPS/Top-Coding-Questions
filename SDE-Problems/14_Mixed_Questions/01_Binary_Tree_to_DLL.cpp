/*
Problem: Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
The left and right pointers in nodes are to be used as previous and next pointers respectively in 
converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
*/

Node* getPredecessor(Node*);
Node* getSuccessor(Node*);

Node* bToDLL(Node* root) {
    if(root->left) {
        root->left = getPredecessor(root->left);
        root->left->right = root;
    }
    if(root->right) {
        root->right = getSuccessor(root->right);
        root->right->left = root;
    }
    
    while(root->left) root = root->left;
    return root;
}


Node* getPredecessor(Node* root) {
    if(root->left==NULL && root->right==NULL) return root;

    if(root->left) {
        root->left = getPredecessor(root->left);
        root->left->right = root;
    }
    if(root->right) {
        root->right = getSuccessor(root->right);
        root->right->left = root;
    }
    
    while(root->right) root = root->right;
    return root;
}

Node* getSuccessor(Node* root) {
    if(root->left==NULL && root->right==NULL) return root;
    
    if(root->left) {
        root->left = getPredecessor(root->left);
        root->left->right = root;
    }
    if(root->right) {
        root->right = getSuccessor(root->right);
        root->right->left = root;
    }
    
    while(root->left) root = root->left;
    return root;
}

/* // Structure for tree and linked list
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/