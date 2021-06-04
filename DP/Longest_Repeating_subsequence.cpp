int Solution::anytwo(string A) {
    int dp[A.length()+1][A.length()+1];
    for(int i=0;i<A.length()+1;i++) dp[i][0]=0;
    for(int i=0;i<A.length()+1;i++) dp[0][i]=0;
    
    for(int i=1;i<A.length()+1;i++){
        for(int j=1;j<A.length()+1;j++){
            if(A[i-1]==A[j-1]&&i!=j) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
    return dp[A.length()][A.length()]>1;
}
