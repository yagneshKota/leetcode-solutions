class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum= 0, bobSum= 0;
        int n= aliceSizes.size();
        int m= bobSizes.size();

        for(int i=0; i<n; i++) aliceSum += aliceSizes[i];
        for(int i=0; i<m; i++) bobSum += bobSizes[i];

        int diff= (bobSum- aliceSum)/2;
        unordered_set<int> set(bobSizes.begin(), bobSizes.end());
        
        for (int a : aliceSizes) {
            if (set.count(a+ diff)) {
                return {a, a+ diff};
            }
        }
        return {};
    }
};