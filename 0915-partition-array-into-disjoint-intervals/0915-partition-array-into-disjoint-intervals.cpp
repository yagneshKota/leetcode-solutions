class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n= nums.size();
        int leftMax= nums[0], currMax= nums[0], idx= 0;

        for(int i= 1; i< n; i++){
            currMax= max(currMax, nums[i]);

            if(nums[i]< leftMax){
                idx= i;
                leftMax= currMax;
            }
        }
        return idx+1;
    }
};