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
    void func(TreeNode *root, int sum, int *ans){
        if(!root) return;
        sum= sum*10 + root->val;
        
        if(!root->left && !root->right) *ans += sum;
        func(root->left, sum, ans);
        func(root->right, sum, ans);

    }
    int sumNumbers(TreeNode* root) {
        int ans= 0;
        func(root, 0, &ans);
        return ans;
    }
};