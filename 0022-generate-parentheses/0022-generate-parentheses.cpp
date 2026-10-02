class Solution {
public:
    vector<string> ans;

    void func(string s, int o, int c, int n){
        if(o== n && c == n){
            ans.push_back(s);
            return;
        }
        if(o < n) func(s+ '(', o+1, c, n);
        if(o > c) func(s+ ')', o, c+1, n);
    }

    vector<string> generateParenthesis(int n) {
        func("", 0, 0, n);
        return ans;
    }
};