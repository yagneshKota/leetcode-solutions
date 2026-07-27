class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n= nums.size();
        if(n<= 1) return 0;
        int l=-1, r=-1, count=0, mx= nums[0];
        
        for(int i=1; i<n; i++){
            mx= max(mx, nums[i]);
            if(nums[i]< mx) r= i;
        }
        if(r== -1) return 0;
        int mn= nums[n-1];
        for(int i=n-2; i>=0; i--){
            mn= min(mn, nums[i]);
            if(nums[i]> mn) l= i;
        }
        sort(nums.begin()+l, nums.begin()+r+1);
        return r-l+1;

    }
};