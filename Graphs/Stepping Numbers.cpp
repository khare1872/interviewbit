int count = 0;
    void solve(int n , int m, int start,vector<int>& ans){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current>=n&&current<=m) ans.push_back(current);
            if(start == 0||current>m) continue;
            int front = current*10+(current%10)+1;
            int back = current*10+(current%10)-1;
            if(current%10==0) q.push(front);
            else if(current%10==9) q.push(back);
            else {
               q.push(back); 
               q.push(front);
            }
        }
        
    }
vector<int> Solution::stepnum(int n, int m) {
    vector<int> ans;
    if(n==m==-1) return ans;
    for(int i =0;i<10;i++){
            solve(n,m,i,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
}
