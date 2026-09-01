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
    void func(TreeNode *root, int tar, int sum,vector<int>v, vector<vector<int>> *ans){
        if(!root) return;
        sum+= root->val;
        v.push_back(root->val);

        if(!root->left && !root->right && sum == tar) ans->push_back(v);
        func(root->left, tar, sum, v, ans);
        func(root->right, tar, sum, v, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        func(root, targetSum, 0, {}, &ans);
        return ans;
    }
};