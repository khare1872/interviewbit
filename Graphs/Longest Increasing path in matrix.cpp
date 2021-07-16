class Solution {
public:
    bool safe(int i,int j,int n,int m){
        if(i<0||j<0||i>=n||j>=m){
            return false;
        }
        return true;
    }
    int dfs(int i,int j,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& v){
        if(!safe(i,j,n,m)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a,b,c,d;
        if(safe(i+1,j,n,m)&&v[i+1][j]>v[i][j]) a=1+dfs(i+1,j,n,m,dp,v);
        else a =1;
        if(safe(i-1,j,n,m)&&v[i-1][j]>v[i][j]) b=1+dfs(i-1,j,n,m,dp,v);
        else b =1;
        if(safe(i,j+1,n,m)&&v[i][j+1]>v[i][j]) c=1+dfs(i,j+1,n,m,dp,v);
        else c =1;
        if(safe(i,j-1,n,m)&&v[i][j-1]>v[i][j]) d=1+dfs(i,j-1,n,m,dp,v);
        else d =1;
        return dp[i][j] = max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        int n = matrix.size();
        int m = matrix[0].size();
        int maxa = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                maxa=max(maxa,dfs(i,j,n,m,dp,matrix));
            }
        }
        return maxa;
    }
};
