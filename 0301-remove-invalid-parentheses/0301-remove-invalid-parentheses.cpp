class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        int x= 0;

        for(char c: s){
            if(c == '(') x++;
            else if(c == ')') x--;

            if(x< 0) return false;
        }
        return true;
    }
    void dfs(string s, int start, int l, int r){
        if(l == 0 && r == 0){
            if(isValid(s))
                ans.push_back(s);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            if(i > start && s[i] == s[i - 1])
                continue;
            
            if(l > 0 && s[i] == '(') {
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, l - 1, r);
            }
            
            if(r > 0 && s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, l, r - 1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int l= 0, r= 0;

        for(char c: s){
            if(c == '(') l++;
            else if(c == ')'){
                if(l> 0) l--;
                else r++;
            }
        }

        dfs(s, 0, l, r);
        return ans;
    }
};