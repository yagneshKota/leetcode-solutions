class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        for(int i=0;i<nums.size(); i++){
            int key=target-nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(key ==nums[j]){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};