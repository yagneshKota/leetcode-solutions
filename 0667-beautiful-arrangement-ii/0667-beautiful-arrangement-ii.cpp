class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i= 1, j= k+1;
        vector<int> ans;
        while(i<= j){
            ans.push_back(i++);
            if(i<= j)
            ans.push_back(j--);
        }
        for(int p= k+2; p<= n; p++)
            ans.push_back(p);
        return ans;
    }
};