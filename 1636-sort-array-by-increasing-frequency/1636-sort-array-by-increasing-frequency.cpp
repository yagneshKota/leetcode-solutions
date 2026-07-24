class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> freq;
        for(int num: nums)
            freq[num]++;
        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            if(a.second != b.second) return a.second <b.second;
            return a.first> b.first;
        });
        vector<int> ans;
        for(auto& [key, val]: v){
            for(int i=0; i<val; i++)
                ans.push_back(key);
        }
        return ans;
    }
};