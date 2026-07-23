class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n= nums.size();
        bool ans= true;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                ans= false;
                break;
            }
        }
        if(ans == true) return ans;
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i])
                return false;
        }
        return true;
    }
};