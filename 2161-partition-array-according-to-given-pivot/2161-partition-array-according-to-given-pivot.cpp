class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        int i= 0, j= n-1;
        int less= 0, high= n-1;
        vector<int> ans(n); 
        while(i< n && j>= 0){
            if(nums[i]< pivot) ans[less++]= nums[i];
            if(nums[j]> pivot) ans[high--]= nums[j];
            i++; j--;
        }
        for(int k= less; k<= high; k++)
            ans[k]= pivot;
        return ans;
    }
};