class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()< 3) return false;
        int i=1;
        for(i=1; i<arr.size()-1; i++){
            if(arr[i-1]== arr[i]) return false;
            if(arr[i-1]> arr[i]) return false;
            if(arr[i-1]< arr[i] && arr[i]> arr[i+1]) break;
        }
        if(i== arr.size()-1) return false;
        for(int j=i; j<arr.size()-1; j++){
            if(arr[j]<= arr[j+1]) return false;
        }
        return true;
    }
};