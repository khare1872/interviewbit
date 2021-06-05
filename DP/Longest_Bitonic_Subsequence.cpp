//find LIS and LDS return max of LIS+LDS-1 of every index
int LongestBitonicSequence(vector<int>nums)
	{
    if(nums.size()==0) return 0;
    int maxlen = 0;
    vector<int> dp(nums.size(), 1);
    vector<int> dp2(nums.size(),1);
    if(nums.size() <= 1) return nums.size();
    //LIS
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
  //LDS
    i=j=nums.size()-1;
    while(i>=0){
        if(i==j){
            i--;
            j=nums.size()-1;
        }
        else {
            if(nums[i]>nums[j]){
                dp2[i]=max(1+dp2[j],dp2[i]);
            }
            j--;
        }
    }
  //Final Calculation
    
    for(int i = 0; i < dp.size(); i++){
        maxlen = max(maxlen, dp[i]+dp2[i]-1);
    }
    
    return maxlen;
	}
