//Recurssion+Memoization
int Solution::climbStairs(int A) {
    if(A<0) return 0;
    if(A==0) return 1;
    vector<int> dp(A+1,-1);
    if(dp[A]!=-1) return dp[A];
    return dp[A]=climbStairs(A-1)+climbStairs(A-2);
}
