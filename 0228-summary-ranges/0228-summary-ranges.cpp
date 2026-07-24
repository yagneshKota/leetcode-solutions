class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()== 0) return ans;
        int j=0, k=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[k]+1){
                if(j== k){
                    ans.push_back(to_string(nums[j]));
                }
                else{
                    string s= to_string(nums[j]) + "->"+ to_string(nums[k]);
                    ans.push_back(s);
                }
                j= i; k=i;
            }
            else k++;
        }
        if(j== k){
            ans.push_back(to_string(nums[j]));
        }
        else{
            string s= to_string(nums[j]) + "->"+ to_string(nums[k]);
            ans.push_back(s);
        }
        return ans;
    }
};