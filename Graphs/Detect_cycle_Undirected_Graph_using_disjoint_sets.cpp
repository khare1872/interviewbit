int find(int a, vector<int>& parent){
    if(parent[a]==-1) return a;
    else return parent[a] = find(parent[a],parent);
}
int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> parent(A+1,-1);
    for(int i = 0;i<B.size();i++ ){
            int s1 = find(B[i][0],parent);
            int s2 = find(B[i][1],parent);
            if(s1!=s2) parent[s2]=s1;
            else return true;
    
        }
    return false;
}
