class Solution {
public:
    void r(vector<int>& num, int i, int j){
        while(i<j){
            swap(num[i], num[j]);
            i++; j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        if(n< k) k %= n;
        r(nums, 0, n-k-1);
        r(nums, n-k, n-1);
        r(nums, 0, n-1);
    }
};