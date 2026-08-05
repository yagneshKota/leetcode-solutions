class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n= arr.size();
        vector<int> ans;
        for(int i= n-1; i>0; i--){
            int idx= max_element(arr.begin(), arr.begin()+i+1)- arr.begin();

            if(idx == i) continue;
            if(idx != 0){
                reverse(arr.begin(), arr.begin()+idx+1);
                ans.push_back(idx+1);
            }
            reverse(arr.begin(), arr.begin()+i+1);
            ans.push_back(i+1);
        }
        return ans;
    }
};