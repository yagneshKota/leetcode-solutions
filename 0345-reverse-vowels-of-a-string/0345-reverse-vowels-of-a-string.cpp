class Solution {
public:
    bool vowels(string s, int k){
        char c= tolower(s[k]);
        if(c == 'a' || c == 'e' ||
           c == 'i' || c == 'o' ||
           c == 'u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i= 0, j= s.length()-1;

        while(i< j){
            while(i<j && !vowels(s, i)) i++;
            while(i<j && !vowels(s, j)) j--;
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};