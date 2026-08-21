class Solution {
public:
    void solve(vector<int>& candidates, int idx, int tar, vector<vector<int>> &ans, 
                vector<int> &current){
        
        if(tar == 0){
            ans.push_back(current);
            return;
        }
        for(int i= idx; i<candidates.size(); i++){
            if(candidates[i] > tar) break;
            current.push_back(candidates[i]);
            solve(candidates, i, tar- candidates[i], ans, current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        vector<vector<int>> ans;
        solve(candidates, 0, target, ans, current);
        return ans;
    }
};