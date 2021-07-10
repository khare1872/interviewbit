bool dfs(int i,int j,string B,int k,vector<string>& A,int n,int m){
if(i>=n||j>=m||i<0||j<0||A[i][j]!=B[k])
return false;
if(k==B.size()-1&&A[i][j]==B[k])
return true;
return dfs(i+1,j,B,k+1,A,n,m)||dfs(i-1,j,B,k+1,A,n,m)||dfs(i,j+1,B,k+1,A,n,m)||dfs(i,j-1,B,k+1,A,n,m);

}
int Solution::exist(vector<string> &A, string B) {
int n=A.size();

int m=A[0].size();

for(int k=0;k<n;k++){
     
    for(int j=0;j<m;j++){

        if(A[k][j]==B[0]){
          
            if(dfs(k,j,B,0,A,n,m))
                return 1;
        }
    }
}
return 0;

}
