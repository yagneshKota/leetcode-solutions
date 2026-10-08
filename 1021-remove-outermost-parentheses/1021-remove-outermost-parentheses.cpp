class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth= 0;
        string ans= "";
        for(char c: s){
            if(c == '('){
                depth++;
                if(depth> 1) ans += c;
            }
            else{
                if(depth> 1) ans += c;
                depth--;
            }
        }
        return ans;
    }
};