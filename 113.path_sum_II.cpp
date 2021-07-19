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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans1;
        allPaths(root, targetSum, 0, ans1);
        return ans2;
    }
    
    vector<vector <int>> ans2;
    
    void allPaths(TreeNode* root, int targetSum, int sum, vector<int> &ans1)
    {
        if(root==NULL)
            return;
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL) // leaf node
        {
            if(sum==targetSum) // target sum found
            {
                ans1.push_back(root->val);
                ans2.push_back(ans1); // push the correct path
                ans1.pop_back();
            }
            return;
        }
        ans1.push_back(root->val);
        allPaths(root->left, targetSum, sum, ans1);
        allPaths(root->right, targetSum, sum, ans1);
        ans1.pop_back();
    }
};