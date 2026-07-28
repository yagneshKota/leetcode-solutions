class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        for(int num : nums1)
            s.insert(num);
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            auto it= s.find(nums2[i]);
            if(it != s.end()){
                ans.push_back(nums2[i]);
                s.erase(it);
            }
        }
        return ans;
    }
};