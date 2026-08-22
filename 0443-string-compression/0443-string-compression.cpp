class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;

        int i= 0, count= 1, idx= 1;
        char c= chars[i];
        while(idx < chars.size()){
            if(chars[idx] != c){
                chars[i++]= c;
                if(count != 1){
                    string str= to_string(count);
                    for(char ch: str)
                        chars[i++]= ch;
                }
                count= 1;
                c= chars[idx];
            }
            else count++;
            idx++;
        }
        chars[i++]= c;
        if(count != 1){
            string str= to_string(count);
            for(char ch: str)
            chars[i++]= ch;
        }
        return i;
    }
};