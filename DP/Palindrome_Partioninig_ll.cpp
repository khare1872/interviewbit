 bool ispalindrome(string str,int i,int j){
         while(i<j){
             if(str[i]!=str[j]) return false;
             i++;
             j--;
         }
         return true;
     }
    int solve(string str,int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(ispalindrome(str,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans= INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(dp[i][k]==-1) dp[i][k]=solve(str,i,k,dp);
            if(dp[k+1][j]==-1) dp[k+1][j]=solve(str,k+1,j,dp);
            int temp = dp[i][k]+dp[k+1][j]+1;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
int Solution::minCut(string str) {
    vector<vector<int>> dp(str.length()+1,vector<int> (str.length()+1,-1));
        return solve(str,0,str.length()-1,dp);
}
