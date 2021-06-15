int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int>(A[0].size(),0));
    int maxa=0;
    for(int i=0;i<A.size();i++) {
        dp[i][0]=A[i][0];
        if(dp[i][0]>maxa) maxa=dp[i][0];
    }
    for(int i=0;i<A[0].size();i++) {
        dp[0][i]=A[0][i];
        if(dp[0][i]>maxa)maxa=dp[0][i];
    }
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            if(A[i][j]==1) dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            else dp[i][j]=A[i][j];
            if(dp[i][j]>maxa) maxa=dp[i][j];
        }
    }
    //for(int i=0;i<A.size();i++) maxa=max(maxa,*max_element(dp[i].begin(),dp[i].end()));
    return maxa*maxa;
}
