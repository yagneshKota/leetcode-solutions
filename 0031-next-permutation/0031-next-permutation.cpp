class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size(), i=0;
        if(n<= 1) return;
        for(i=n-2; i>=0; i--){
            if(nums[i]< nums[i+1]) break;
        }
        if(i>=0){
        int j;
        for(j= n-1; j>0; j--){
            if(nums[j]> nums[i]) break;
        }
        swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};