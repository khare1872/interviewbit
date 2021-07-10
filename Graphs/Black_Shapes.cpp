bool isSafe(int x,int y,int n,int m){
    return (x>=0&&y>=0&&x<n&&y<m);
}


int Solution::black(vector<string> &A) {
    queue<pair<int,int>> q;
    int n = A.size();
    int m = A[0].size();
    int count = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(A[i][j]=='X'){
                count++;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    A[x][y]='O';
                    if(isSafe(x+1,y,n,m)&&A[x+1][y]=='X') q.push({x+1,y});
                    if(isSafe(x,y+1,n,m)&&A[x][y+1]=='X') q.push({x,y+1});
                    if(isSafe(x-1,y,n,m)&&A[x-1][y]=='X') q.push({x-1,y});
                    if(isSafe(x,y-1,n,m)&&A[x][y-1]=='X') q.push({x,y-1});
                }
            }
        }
    }
    return count;
}
