class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n= arr.size();
        int zeroes= 0;
        for(int x : arr)
            if(x== 0) zeroes++;
        int i= n-1;
        int j= n-1+ zeroes;
        while(i < j){
            if(j< n)
                arr[j]= arr[i];
            if(arr[i]== 0){
                j--;
                if(j<n) arr[j]= 0;
            }
            i--;
            j--;
        }
    }
};