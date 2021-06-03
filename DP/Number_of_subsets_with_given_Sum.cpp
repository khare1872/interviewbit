//Similar count subsets with sum k in unbounded knapsack

class Solution {
public:
    int change(int n, vector<int>& S) {
       int m=S.size();
       int dp[m+1][n+1];
      //initialization
       for(int i =0;i<n+1;i++) dp[0][i]=0;
       for(int i=0;i<m+1;i++) dp[i][0]=1;
       for(int i=1;i<m+1;i++){
           for(int j=1;j<n+1;j++){
              if(j>=S[i-1]) dp[i][j]=dp[i-1][j]+dp[i][j-S[i-1]];
              else dp[i][j]=dp[i-1][j];
           }
       }
       return dp[m][n];
        
    }
};
