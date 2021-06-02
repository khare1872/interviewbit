//Recurssion+Memoization
int solve(int A, vector<int> & dp){
    if(A<0) return 0;
    if(A==0) return 1;
    if(dp[A]!=-1) return dp[A];
    return dp[A]=solve(A-1,dp)+solve(A-2,dp);
}
int Solution::climbStairs(int A) {
    if(A<0) return 0;
    if(A==0) return 1;
    vector<int> dp(A+1,-1);
    return solve(A,dp);
}
//Bottom-up
int Solution::climbStairs(int A) {
    if(A<0) return 0;
    if(A==0) return 1;
    vector<int> dp(A+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i =2;i<A+1;i++){
       dp[i]=dp[i-1]+dp[i-2]; 
    }
    return dp[A];
    
}
