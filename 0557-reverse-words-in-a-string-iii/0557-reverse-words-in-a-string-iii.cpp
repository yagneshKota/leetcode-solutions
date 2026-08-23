class Solution {
public:
    string reverseWords(string s) {
        int st= 0;
        for(int i= 0; i<= s.length(); i++){
            if(i == s.length() || s[i] == ' '){
                reverse(s.begin()+ st, s.begin()+i);
                st= i+1;
            }
        }
        return s;
    }
};