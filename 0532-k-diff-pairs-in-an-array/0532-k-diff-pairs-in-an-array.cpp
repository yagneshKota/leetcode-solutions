class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k< 0) return 0;

        unordered_map<int, int> freq;

        for(int num: nums)
            freq[num]++;
        int count= 0;
        if(k== 0){
            for(auto map : freq){
                if(map.second >= 2) count++;
            }
            return count;
        }

        for(auto map: freq){
            if(freq.count(map.first + k)) count++;
        }
        return count;
    }
};