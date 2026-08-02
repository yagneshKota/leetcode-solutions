class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        for(int i= 0; i<nums.size(); i++){
            if(freq[nums[i]]== 0)
                first[nums[i]]= i;
            freq[nums[i]]++;
            last[nums[i]]= i;
        }

        int max_freq= 0;
        for(auto map: freq)
            if(map.second> max_freq)
                max_freq= map.second;
        
        int ans= INT_MAX;
        for(auto map: freq){
            if(max_freq == map.second)
                ans= min(ans, last[map.first]- first[map.first]+1);
        }
        return ans;
    }
};