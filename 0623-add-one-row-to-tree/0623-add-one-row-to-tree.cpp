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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);

        dfs(root, val, depth, 1);

        return root;
    }

    void dfs(TreeNode* root, int val, int depth, int curr) {
        if (!root) return;

        if (curr == depth - 1) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = left;
            root->right->right = right;

            return;
        }

        dfs(root->left, val, depth, curr + 1);
        dfs(root->right, val, depth, curr + 1);
    }
};