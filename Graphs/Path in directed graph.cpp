int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> v(A+1);
    for(int i =0;i<B.size();i++) v[B[i][0]].push_back(B[i][1]);
    vector<int> visited(A+1,0);
    queue<int> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current==A) return 1;
        else {
            for(int i =0;i<v[current].size();i++){
                if(!visited[v[current][i]]) {
                    q.push(v[current][i]);
                    visited[v[current][i]]=1;
                }
            }
        }
    }
    return 0;
}
