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
    int total_sum=0;
    int sumNumbers(TreeNode* root) {
        pathSum(root,0);
        return total_sum;
    }
    
    void pathSum(TreeNode *root, int temp_sum)
    {
        if(root==NULL)
            return;
        int new_temp_sum = temp_sum*10 + root->val;
        if(root->left==NULL && root->right==NULL) // leaf node
            total_sum = total_sum + new_temp_sum;
        pathSum(root->left,new_temp_sum);
        pathSum(root->right,new_temp_sum);
    }
};