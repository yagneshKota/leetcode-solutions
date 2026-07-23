class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int ls= 0, rs= 0;
        for(int i=0; i<n; i++)
            rs += nums[i];
        for(int i=0; i<n; i++){
            rs -= nums[i];
            if(ls == rs) return i;
            ls += nums[i];
        }
        return -1;
    }
};