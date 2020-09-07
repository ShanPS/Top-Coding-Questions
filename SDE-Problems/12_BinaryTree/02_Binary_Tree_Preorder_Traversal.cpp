/*
Problem: Given a binary tree, return the preorder traversal of its nodes' values.

link: https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

class Solution {
    void doPreorderTraversal(TreeNode* root, vector<int> &preorderElements) {
        if(root == NULL) return;
        
        preorderElements.push_back(root->val);
        doPreorderTraversal(root->left, preorderElements);
        doPreorderTraversal(root->right, preorderElements);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderElements;        
        doPreorderTraversal(root, preorderElements);

        return preorderElements;
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