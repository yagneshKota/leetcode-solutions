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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode *a= que.front();
            que.pop();
            TreeNode *b= que.front();
            que.pop();

            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;

            que.push(a->left);
            que.push(b->left);

            que.push(a->right);
            que.push(b->right);
        }
        return true;
    }
};