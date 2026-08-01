class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int count1= 1, val1= nums[0];
        int val2= 0, count2= 0;
        for(int i=1; i<n; i++){
            if(val1 == nums[i]) count1++;
            else if(val2 == nums[i]) count2++;
            else if(count1 == 0){
                count1= 1;
                val1= nums[i];
            }
            else if(count2 == 0){
                count2= 1;
                val2= nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        count1= count2= 0;
        for(int num : nums){
            if(num == val1) count1++;
            else if(num == val2) count2++;
        }
        vector<int> ans;
        if(count1 > n/3) ans.push_back(val1);
        if(count2 > n/3) ans.push_back(val2);
        return ans;
    }
};