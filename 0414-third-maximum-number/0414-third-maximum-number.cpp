class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n= nums.size();
        long long int fl= nums[0], sl= LONG_MIN, tl= LONG_MIN; 
        for(int i=1; i<n; i++){
            if(nums[i]== fl || nums[i]==sl || nums[i]== tl) continue;
            if(nums[i]> fl){
                tl= sl; sl= fl, fl= nums[i];
            }
            else if(nums[i]> sl){
                tl= sl; sl= nums[i];
            }
            else if(nums[i]> tl) tl= nums[i];
        }
            if(tl != LONG_MIN) return tl;
            return fl;
    }
};