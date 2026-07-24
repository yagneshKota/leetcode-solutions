class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n= nums.size();
        vector<bool> find(n, false);
        for(int i=0; i<n; i++){
            find[nums[i]-1]= true;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(find[i]== false){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};