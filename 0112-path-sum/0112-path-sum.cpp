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
    bool pathSum(TreeNode *root, int tar, int sum){
        if(!root) return false;
        sum += root->val;

        if(!root->left && !root->right ) 
            return tar == sum; 
        return pathSum(root->left, tar, sum) || pathSum(root->right, tar, sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return pathSum(root, targetSum, 0);
    }
};