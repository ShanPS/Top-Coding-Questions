/*
Problem: Given the root of a binary tree, return the postorder traversal of its nodes' values.

link: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

class Solution {
    void doPostorderTraversal(TreeNode* root, vector<int> &postorderElements) {
        if(root == NULL) return;
        
        doPostorderTraversal(root->left, postorderElements);
        doPostorderTraversal(root->right, postorderElements);
        postorderElements.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderElements;        
        doPostorderTraversal(root, postorderElements);

        return postorderElements;
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