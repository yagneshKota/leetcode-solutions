class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int i= 0;
        while(i< n && nums[i]== nums[0]) i++;
        int j= n-1;

        while(j>= 0 && nums[j]== nums[n-1]) j--;
        return max(0, j-i+1);
    }
};