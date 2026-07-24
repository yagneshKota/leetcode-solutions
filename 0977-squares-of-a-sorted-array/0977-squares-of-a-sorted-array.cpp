class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(nums[i] >=0) break;
            nums[i]= -nums[i];
        }
        int i= 0, j= n-1, k=n-1;
        while(i<=j){
            if(nums[i] > nums[j]){
                ans[k--]= nums[i]* nums[i];
                i++;
            }
            else{
                ans[k--]= nums[j]* nums[j];
                j--;
            }
        }
        return ans;
    }
};