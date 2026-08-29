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
    bool func(TreeNode *root, int x){
        if(!root) return true;
        if(root->val != x) return false;
        return func(root->left, x) && func(root->right, x);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return func(root, root->val);
    }
};