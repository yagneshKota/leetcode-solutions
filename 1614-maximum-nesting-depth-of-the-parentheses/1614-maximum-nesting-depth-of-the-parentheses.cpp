class Solution {
public:
    int maxDepth(string s) {
        int ans= 0, n= 0;
        for(char ch : s){
            if(ch == ')') n--;
            else if(ch == '('){
                n++;
                ans= max(ans, n);
            }
        }
        return ans;
    }
};