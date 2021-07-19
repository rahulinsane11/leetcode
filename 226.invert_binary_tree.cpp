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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // RECURSIVE
        inv(root);
        return root;
    }
    
    void inv(TreeNode* root)
    {
        if(root==NULL)
            return;
        TreeNode* temp=root->right; // swap left and right child
        root->right=root->left;
        root->left=temp; 
        inv(root->left); // go to left subtree
        inv(root->right); // go to right subtree
    }
};