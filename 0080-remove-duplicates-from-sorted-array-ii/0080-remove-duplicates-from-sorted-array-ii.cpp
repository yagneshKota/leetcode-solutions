class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size(), k=0, val= nums[0], count= 1;
        for(int i=1; i<n; i++){
            if(val!= nums[i]){
                if(count >= 2){
                    nums[k]= val;
                    nums[k+1]= val;
                    k= k+2;
                }
                else{
                    nums[k]= val;
                    k++;
                }
                val= nums[i];
                count= 1;
            }
            else count++;
        }
        if(count>= 2){
            nums[k]= val;
            nums[k+1]= val;
            k= k+2;
        }
        else{
            nums[k]= val;
            k++;
        }
        return k;
    }
};