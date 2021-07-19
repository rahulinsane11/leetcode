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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum);
    }
    
    bool pathSum(TreeNode* root,int sum)
    {
        if(root==NULL) // empty tree
            return false;
        if(root->left==NULL && root->right==NULL) // leaf node
        {
            if(sum == root->val)
                return true;
            else
                return false;
        }
        sum = sum - root->val;
        return pathSum(root->left,sum) || pathSum(root->right,sum);
    }
};