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
    void func(TreeNode *root, vector<string> &v, string s){
        if(!root) return;
        s += to_string(root->val);

        if(!root->left && !root->right){
            v.push_back(s);
            return;
        }
        s += "->";
        
        func(root->left, v, s);
        func(root->right, v, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        func(root, ans, "");
        return ans;
    }
};