class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd= 1, even= 0, i= 0;
        vector<int> ans(nums.size());
        while(i< nums.size()){
            if(nums[i]%2 == 0){
                ans[even]= nums[i];
                even += 2;
            }
            else{
                ans[odd]= nums[i];
                odd += 2;
            }
            i++;
        }
        return ans;
    }
};