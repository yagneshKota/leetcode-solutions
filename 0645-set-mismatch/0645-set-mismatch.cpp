class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        int i=0, count= 0;
        while(i<n){
            if(nums[i] == nums[nums[i]-1]){
                if(i != nums[i]-1 && count== 0){
                    ans.push_back(nums[i]);
                    count++;
                }
                else swap(nums[i], nums[nums[i]-1]);
                i++;
            }
            if(i<n)
            swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0; i<n; i++)
            if(nums[i] != i+1)
                ans.push_back(i+1);
        return ans;
    }
};