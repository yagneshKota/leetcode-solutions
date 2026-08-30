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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root || !root->left) return -1;

        int left= findSecondMinimumValue(root->left);
        int right= findSecondMinimumValue(root->right);

        if(root->left->val != root->val) left= root->left->val;
        if(root->right->val != root->val) right= root->right->val;

        if(left == -1) return right;
        if(right == -1) return left;

        return min(left, right);
    }
};