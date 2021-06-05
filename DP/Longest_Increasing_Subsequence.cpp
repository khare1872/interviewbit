int Solution::lis(const vector<int> &nums) {
    int maxlen = 0;
    vector<int> dp(nums.size(), 1);
    
    if(nums.size() <= 1) return nums.size();
    
    int i=0,j=0;
    while(i<nums.size()){
        if(i==j){
            i++;
            j=0;
        }
        else {
            if(nums[i]>nums[j]){
                dp[i]=max(1+dp[j],dp[i]);
            }
            j++;
        }
    }
    
    for(int i = 0; i < dp.size(); i++){
        maxlen = max(maxlen, dp[i]);
    }
    
    return maxlen;
}
