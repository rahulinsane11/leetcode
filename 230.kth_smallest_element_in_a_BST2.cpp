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
    int count, small;

    int kthSmallest(TreeNode* root, int k) {
        count=k;
        inorder(root); // inorder traversal of BST gives a sorted array (in ascending order)
        return small;
    }
    
    void inorder(TreeNode *root) // RECURSIVE
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(count>0)          // sort only the first k elements
        {                    //
            small=root->val; //
            count--;         //
        }                    //
        else                 // return after sorting the first k elements  
            return;          //   
        inorder(root->right);
    }
};