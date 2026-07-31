class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        if(n== 1) return {0};
        vector<int> rightSum(n);
        int rsum= 0;
        for(int i= n-1; i>=0; i--){
            rightSum[i]= rsum;
            rsum += nums[i];
        }
        int lsum= 0;
        vector<int> ans(n);
        for(int i= 0; i<n; i++){
            int res= lsum- rightSum[i];
            if(res< 0) res= -res;
            ans[i]= res;
            lsum+= nums[i];
        }
        return ans;

    }
};