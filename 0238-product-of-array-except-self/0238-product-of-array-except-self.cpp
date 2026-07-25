class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> left;
        left.push_back(1);
        int pro= 1;
        for(int i=1; i<n; i++){
            pro *= nums[i-1];
            left.push_back(pro);
        }
        vector<int> ans(n);
        pro= 1;
        for(int i=n-1; i>=0; i--){
            ans[i]= pro*left[i];
            pro *= nums[i];
        }
        return ans;
    }
};