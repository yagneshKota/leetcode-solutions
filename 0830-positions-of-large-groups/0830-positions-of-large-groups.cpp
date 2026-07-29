class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n= s.size();
        int st= 0;
        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            if(s[st] != s[i]){
                if((i-st) >= 3){
                    ans.push_back({st, i-1});
                }
                st= i;
            }
        }
        if((n-st) >= 3){
            ans.push_back({st, n-1});
        }
        return ans;
    }
};