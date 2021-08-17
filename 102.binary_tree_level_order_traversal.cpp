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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root==NULL) // tree is empty
            return levels;
        TreeNode *curr;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int len=qu.size();
            vector<int> level;
            while(len--)
            {
                curr=qu.front();
                qu.pop();
                level.push_back(curr->val);
                if(curr->left!=NULL) // if left child exists
                    qu.push(curr->left); // push the left child in queue
                if(curr->right!=NULL)  // if right child exists
                    qu.push(curr->right); // push the right child in queue
            }
            levels.push_back(level);
        }
        return levels;
    }
};