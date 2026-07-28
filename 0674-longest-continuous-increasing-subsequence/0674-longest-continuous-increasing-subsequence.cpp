class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx= 0, cur= 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] < nums[i]) cur++;
            else{
                mx= max(mx, cur);
                cur= 1;
            }
        }
        mx= max(mx, cur);
        return mx;
    }
};