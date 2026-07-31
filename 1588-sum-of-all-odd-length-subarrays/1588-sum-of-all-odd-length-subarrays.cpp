class Solution {
public:
    int sum(int i, int j, vector<int>arr){
        int sum= 0;
        for(int k= i; k<=j; k++)
            sum += arr[k];
        return sum;
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n= arr.size();
        int ans= 0;
        for(int i= 0; i< n; i++){
            for(int j= 0; j< n; j++){
                if((j-i)%2 == 0)
                    ans += sum(i, j, arr);
            }
        }
        return ans;
    }
};