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
    TreeNode* invertTree(TreeNode* root) { // ITERATIVE
        if(root==NULL)
            return root;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* curr=qu.front();
            qu.pop();
            TreeNode* temp=curr->right; // swap left and right child of current node
            curr->right=curr->left;
            curr->left=temp;
            if(curr->left!=NULL)
                qu.push(curr->left);
            if(curr->right!=NULL)
                qu.push(curr->right);
        }
        return root;
    }
};