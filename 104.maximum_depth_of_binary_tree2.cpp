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
    int maxDepth(TreeNode* root) { // ITERATIVE
        if(root==NULL)
            return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int level=0,s;
        while(!qu.empty())
        {
            level++;
            s=qu.size();
            for(int i=1; i<=s; i++)
            {
                TreeNode* curr=qu.front();
                qu.pop();
                if(curr->left!=NULL)
                    qu.push(curr->left);
                if(curr->right!=NULL)
                    qu.push(curr->right);
            }
        }
        return level;
    }
};