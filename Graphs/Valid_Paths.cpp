int r[8]={-1,-1,0,1,1,1,0,-1};
int c[8]={0,1,1,1,0,-1,-1,-1};
bool incircle(vector<int> &xc, vector<int> &yc, int R, int i,int j){
    for(int k=0;k<xc.size();k++){
        if((xc[k]-i)*(xc[k]-i)+(yc[k]-j)*(yc[k]-j)<=R*R)return true;
    }
    return false;
}
string Solution::solve(int x, int y, int n, int R, vector<int> &xc, vector<int> &yc){
    queue<pair<int,int>>q;
    q.push({0,0});
    vector<vector<int>>vis(105,vector<int>(105,0));
    vis[0][0]=1;
    int flag=0;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            if(i+r[k]>=0 and i+r[k]<=x and j+c[k]>=0 and j+c[k]<=y and !vis[i+r[k]][j+c[k]] and !incircle(xc,yc,R,i+r[k],j+c[k])){
                vis[i+r[k]][j+c[k]]=1;
                if(i+r[k]==x and j+c[k]==y){
                    flag=1;
                    break;
                }
                q.push({i+r[k],j+c[k]});
            }
        }
        if(flag)break;
    }
    if(flag)return "YES";
    return "NO";
}
