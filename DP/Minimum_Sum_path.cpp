//Bottom-up
int Solution::minPathSum(vector<vector<int> > &grid) {
     int n = grid.size();
        int m = grid[0].size();
        if(m==1&&n==1) return grid[0][0];
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int j=1;j<m;j++) dp[0][j]=grid[0][j]+dp[0][j-1];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
}
//Recursive + memoization
 int solve(vector<vector<int>> grid,int n, int m, vector<vector<int>> &dp){
        if(n==grid.size()-1&&m==grid[0].size()-1) return grid[grid.size()-1][grid[0].size()-1];
        if(n>=grid.size()||m>=grid[0].size()) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        else {
            return dp[n][m]=grid[n][m]+min(solve(grid,n+1,m,dp),solve(grid,n,m+1,dp));
        }
    }
int Solution::minPathSum(vector<vector<int> > &grid) {
     int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,dp);
}
