class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size(), val= nums[0], count= 1;
        for(int i=1; i<n; i++){
            if(nums[i]== val) count++;
            else count--;
            if(count< 0){
                val= nums[i];
                count=1;
            }
        }
        return val;
    }
};