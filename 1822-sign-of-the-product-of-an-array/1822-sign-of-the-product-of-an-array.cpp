class Solution {
public:
    int sign(int x){
        if(x> 0) return 1;
        else if(x< 0) return -1;
        else return 0;
    }
    int arraySign(vector<int>& nums) {
        long long int product= 1;
        for(int num: nums)
            product *= sign(num);
        return sign(product);
    }
};