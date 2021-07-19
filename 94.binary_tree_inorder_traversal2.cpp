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
    vector<int> vec;
    vector<int> inorderTraversal(TreeNode* root) { // ITERATIVE
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(1)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            if(st.empty())
                break;
            curr=st.top();
            st.pop();
            vec.push_back(curr->val);
            curr=curr->right;
        }
        return vec;
    }
};