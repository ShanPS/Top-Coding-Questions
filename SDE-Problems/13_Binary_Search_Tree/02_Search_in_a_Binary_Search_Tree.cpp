/*
Problem: Given the root node of a binary search tree (BST) and a value. 
You need to find the node in the BST that the node's value equals the given value.
Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

link: https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curNode = root;
        
        while(curNode) {            
            if(curNode->val == val)
                return curNode;
            else if(curNode->val < val)
                curNode = curNode->right;
            else
                curNode = curNode->left;
        }
        
        return NULL;
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