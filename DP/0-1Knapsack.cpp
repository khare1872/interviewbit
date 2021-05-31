//Bottom-up
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<int>> vec( A.size()+1 , vector<int> (C+1));
    for(int i = 0;i<=A.size();i++) vec[i][0]=0;
    for(int i = 0;i<=C;i++) vec[0][i]=0;
    
    for(int i =1;i<=A.size();i++){
        for(int j = 1;j<=C;j++){
            if(B[i-1]<=j){
                vec[i][j]=max(A[i-1]+vec[i-1][j-B[i-1]],vec[i-1][j]);
            }
            else vec[i][j]=vec[i-1][j];
        }
    }
    return vec[A.size()][C];
    
}
//Memoization+recurssion
int solves(vector<int> &A, vector<int> &B, int C,int n,vector<vector<int>> &vec){
    if(n==0||C==0) return 0;
    if(vec[n][C]!=-1) return vec[n][C];
    if(B[n-1]<=C) return vec[n][C]=max(A[n-1]+solves(A,B,C-B[n-1],n-1,vec),solves(A,B,C,n-1,vec));
    else return solves(A,B,C,n-1,vec);
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<int>> vec( A.size()+1 , vector<int> (C+1, -1));
    return solves(A,B,C,A.size(),vec);
    
}
