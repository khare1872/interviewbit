#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check(int x,int y,int n,int m,vector<vector<char>> &res,vector<vector<int>> &vis){
    if(x<0||y<0||x>n||y>m||vis[x][y]==1) return false;
    return res[x][y]!='#';
}
int solve(int x, int y,vector<vector<char>>& res,int n,int m,vector<vector<int>>& vis){
    if(x==n&&y==m) return 1;
    if(x<0||y<0||x>n||y>m) return 0;
    if(res[x][y]=='#') return 0;
    else{
        vis[x][y]=1;
        int a  = 0;
        for(int i = 0;i<4;i++){
            if(check(x+dx[i],y+dy[i],n,m,res,vis))
                a= max(a,solve(x+dx[i],y+dy[i],res,n,m,vis));
             }
           return a;
        }
       
    }
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char> (m));
    vector<vector<char>> res(n,vector<char>(m,'.'));
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++) cin>>v[i][j];
    }
    int x,y;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j]=='A') {
                x=i;
                y=j;
            }
            if(v[i][j]=='X') res[i][j]='#';
            else if(v[i][j]=='>'){
                res[i][j]='#';
                for(int k = j;k<m;k++){
                    if(v[i][k]=='X') {
                        res[i][k]='#';
                        break;
                    }
                    else if(v[i][k]=='A') {
                        cout<<"false"<<endl;
                        return 0;
                    }
                    else if(v[i][k]!='X') res[i][k] = '#'; 
                }
            }
            else if(v[i][j]=='<'){
                res[i][j]='#';
               for(int k = j;k>=0;k--){
                    if(v[i][k]=='X') {
                        res[i][k]='#';
                        break;
                    }
                    else if(v[i][k]=='A') {
                        cout<<"false"<<endl;
                        return 0;
                    }
                    else if(v[i][k]!='X') res[i][k] = '#'; 
                } 
            }
             else if(v[i][j]=='^'){
                 res[i][j]='#';
               for(int k = i;k>=0;k--){
                    if(v[k][j]=='X') {
                        res[k][j]='#';
                        break;
                    }
                    else if(v[k][j]=='A') {
                        cout<<"false"<<endl;
                        return 0;
                    }
                    else if(v[k][j]!='X') res[k][j] = '#'; 
                } 
            }
            else if(v[i][j]=='v'){
                res[i][j]='#';
                for(int k = i;k<n;k++){
                    if(v[k][j]=='X') {
                        res[k][j]='#';
                        break;
                    }
                    else if(v[k][j]=='A') {
                        cout<<"false"<<endl;
                        return 0;
                    }
                    else if(v[k][j]!='X') res[k][j] = '#'; 
                }
            }
        }
    }
    if(v[n-1][m-1]=='.') res[n-1][m-1] = '.';
    vector<vector<int>> vis(n,vector<int>(m,0));
    cout<<solve(x,y,res,n-1,m-1,vis)<<endl;
    return 0;
}
