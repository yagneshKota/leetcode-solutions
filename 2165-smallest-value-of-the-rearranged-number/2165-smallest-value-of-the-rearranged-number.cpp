class Solution {
public:
    long long smallestNumber(long long n) {
        if(n == 0) return 0;
        vector<int> v;
        long long int num= abs(n);
        while(num != 0){
            v.push_back(num%10);
            num /= 10;
        }
        long long int ans= 0;
        if(n > 0){
            sort(v.begin(), v.end());
            ans= v[0];
            int count= 0, i= 0;
            while(v[i] == 0){count++; i++;}
            ans= v[i];
            while(count> 0){
                ans *= 10;
                count--;
            }
            i++;
            while(i< v.size()) ans = ans*10 + v[i++];
        }
        else{
            sort(v.begin(), v.end(), greater<int>());
            int i= 0;
            while(i< v.size()) ans = ans*10 + v[i++];
            ans= - ans;
        }
        return ans;
    }
};