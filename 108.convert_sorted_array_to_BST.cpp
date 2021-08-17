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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size(), left=0, right=n-1;
        TreeNode* root = toBST(nums,left,right);
        return root;
    }

    TreeNode* toBST(vector<int>& nums, int left, int right)
    {
        if(left<=right)
        {
            int mid = left+(right-left)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = toBST(nums,left,mid-1);
            root->right = toBST(nums,mid+1,right);
            return root;
        }
        return NULL; // leaf node is reached
    }
};