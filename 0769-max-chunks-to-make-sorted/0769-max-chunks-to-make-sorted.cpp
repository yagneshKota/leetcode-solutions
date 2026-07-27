class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n= arr.size();
        if(n<= 1) return n;
        int count= 0;
        int mx= 0;
        for(int i=0; i<n; i++){
            mx= max(mx, arr[i]);
            if(mx== i) count++;
        }
        
        return count;
    }
};