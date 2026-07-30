class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> ans;
        for(int i= n-1; i>=0; i--){
            k += nums[i];
            ans.push_back(k% 10);
            k /= 10;
        }
        while(k > 0){
            ans.push_back(k%10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
            
    }
};