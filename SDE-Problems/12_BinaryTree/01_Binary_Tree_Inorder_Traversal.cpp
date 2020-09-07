/*
Problem: Given a binary tree, return the inorder traversal of its nodes' values.

link: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

class Solution {
    void doInorderTraversal(TreeNode* root, vector<int> &inorderElements) {
        if(root == NULL) return;
        
        doInorderTraversal(root->left, inorderElements);
        inorderElements.push_back(root->val);
        doInorderTraversal(root->right, inorderElements);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderElements;        
        doInorderTraversal(root, inorderElements);

        return inorderElements;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */