class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n= img.size();
        int m= img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum= 0, count=0;
                for(int k= i-1; k<= i+1; k++){
                    for(int l=j-1; l<= j+1; l++){
                        if(k>=0 &&k<n && l>=0 && l<m){
                            sum += img[k][l];
                            count++;
                        }
                    }
                }
                ans[i][j]= sum/count;
            }
        }
        return ans;
    }
};