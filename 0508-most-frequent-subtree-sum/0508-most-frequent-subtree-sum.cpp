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
    int dfs(TreeNode *root, unordered_map<int, int> &freq){
        if(!root) return 0;
        int l= dfs(root->left, freq);
        int r= dfs(root->right, freq);

        int sum= root->val + l + r;
        freq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        dfs(root, freq);
        int maxFreq= 0;
        for(auto &[sum, count] : freq){
            maxFreq= max(maxFreq, count);
        }

        vector<int> ans;
        for(auto &[sum, count]: freq){
            if(maxFreq == count)
                ans.push_back(sum);
        }
        return ans;

    }
};