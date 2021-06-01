//Bottom up approach
int Solution::solve(vector<int> &A, int B) {
    vector<vector<int>> v(A.size()+1,vector<int> (B+1));
    //int v[A.size()+1][B+1];
    for(int i =0;i<B+1;i++) v[0][i]=0;
    for(int i =0;i<A.size()+1;i++) v[i][0]=1;
    for(int i = 1;i<A.size()+1;i++){
        for(int j =1;j<B+1;j++){
               if(j>=A[i-1]){
                   v[i][j]=v[i-1][j]||v[i-1][j-A[i-1]];
               }
               else v[i][j]=v[i-1][j];
            }
        }
        return v[A.size()][B];
    }
//Top-down approach
bool rec(int n,int W,vector<int> &A,vector<vector<int>> &dp)
{
    if(W==0) return true;
    if(n==0&&W!=0) return false;
    if(dp[n][W]!=-1) return (bool)dp[n][W];
    if(A[n-1]>W) dp[n][W]=(int)rec(n-1,W,A,dp);
    else dp[n][W]=(int)(rec(n-1,W,A,dp)||rec(n-1,W-A[n-1],A,dp));
    return (bool)dp[n][W];
}
int Solution::solve(vector<int> &A, int B) {
    vector<vector<int>> dp(A.size()+1,vector<int>(B+1,-1));
    return rec(A.size(),B,A,dp);
}
