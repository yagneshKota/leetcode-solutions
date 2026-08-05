class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>> ans;

        for(int i= 0; i< n-3; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            for(int j= i+1; j<n-2; j++){
                if(j> i+1 && nums[j-1]== nums[j]) continue;
                int k= j+1, l= n-1;
                while(k< l){
                    long long int sum= 1LL * nums[i]+ nums[j]+ nums[k]+ nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                        while(k<l && nums[k-1] == nums[k]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};