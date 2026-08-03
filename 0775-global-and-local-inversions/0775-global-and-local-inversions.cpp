class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n= nums.size();
        int maxSoFar= nums[0];

        for(int j= 2; j<n; j++){
            maxSoFar= max(maxSoFar, nums[j-2]);
            if(nums[j] <maxSoFar)
                return false;
        }
            
        
        return true;
    }
};