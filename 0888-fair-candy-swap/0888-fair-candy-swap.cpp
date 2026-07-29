class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum= 0, bobSum= 0;
        int n= aliceSizes.size();
        int m= bobSizes.size();

        for(int i=0; i<n; i++) aliceSum += aliceSizes[i];
        for(int i=0; i<m; i++) bobSum += bobSizes[i];

        int x= (aliceSum- bobSum)/2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int diff= aliceSizes[i]- bobSizes[j];
                if(diff == x ){
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }
        return {};
    }
};