class Solution {
public:
    int solve(string &str,int start, int end,vector<vector<int>> &dp){
    if(start>=end) return 0;
    if(dp[start][end]!=-1) return dp[start][end];
        if(str[start]==str[end]) return dp[start][end]= solve(str,start+1,end-1,dp);
        else  return dp[start][end]= 1+ min(solve(str,start+1,end,dp),solve(str,start,end-1,dp));
    }
    int minInsertions(string str) {
        vector<vector<int>> dp(str.length(),vector<int> (str.length(),-1));
        return solve(str,0,str.length()-1,dp);
    }
};
