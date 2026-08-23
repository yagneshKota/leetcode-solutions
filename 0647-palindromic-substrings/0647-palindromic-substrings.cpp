class Solution {
public:
    int countSubstrings(string s) {
        int st= 0, ans= 0;
        int n= s.length();
        for(int i= 0; i< n; i++){
            int l= i, r= i;
            while(l>=0 && r<n){
                if(s[l] != s[r]) break;
                ans++;
                l--;
                r++;
            }

            l= i;
            r= i+1;
            while(l>=0 && r<n){
                if(s[l] != s[r]) break;
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};