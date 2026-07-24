class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx= max_element(nums.begin(), nums.end())-nums.begin();
        for(int num: nums){
            if(num == nums[idx]) continue;
            if(nums[idx] < num*2) return -1;
        }
        return idx;
    }
};