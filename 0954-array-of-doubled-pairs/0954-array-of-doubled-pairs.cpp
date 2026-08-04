class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            return abs(a)< abs(b);
        });
        
        unordered_map<int, int> freq;
        for(int num: arr)
            freq[num]++;
        
        for(auto num : arr){
            if(freq[num] == 0) continue;
            if(freq[2*num]== 0) return false;

            freq[2*num]--;
            freq[num]--;
        }
        
        return true;
    }
};