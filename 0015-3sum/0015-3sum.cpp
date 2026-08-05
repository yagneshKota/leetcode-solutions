class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();

        vector<vector<int>> ans;
        int i= 0;
        while(i< (n-2)){
            int j= i+1, k= n-1;
            while(j< k){
                long long int val= 1LL * (nums[j]+nums[k]+nums[i]);
                if(val == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(val > 0) k--;
                else j++;
            }
            while(i< n-2 && nums[i] == nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};