int findNumbers(int* nums, int numsSize) {
    int ans= 0;
    for(int i=0; i<numsSize; i++){
        int count= 0;
        while(nums[i] != 0){
            count++;
            nums[i] /= 10;
        }
        if(count % 2== 0) ans++;
    }
    return ans;
}