bool compare(const vector<int> a,const vector<int> b) {
    return a[2]<b[2];
}
int find(int a,vector<int>& parent){
    if(parent[a]==-1) return a;
    else return parent[a]=find(parent[a],parent);
}
int Solution::solve(int n, vector<vector<int> > &times) {
    sort(times.begin(),times.end(),compare);
    int sum = 0;
    int edges = 0;
    int i =0;
    vector<int> parent(n+1,-1);
    while(edges<n&&i<times.size()){
        int s1 = find(times[i][0],parent);
        int s2 = find(times[i][1],parent);
        if(s1!=s2){
            sum+=times[i][2];
            parent[s2]=s1;
            edges++;
        }
        i++;
    }
    return sum;
    
}
