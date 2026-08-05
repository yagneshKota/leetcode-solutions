class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        int i= 0, j= n-1;

        while(i< j){
            int x= nums[i]+ nums[j];
            if(x == target) return {i+1 , j+1};
            else if(x > target) j--;
            else i++;
        }
        return {};
    }
};