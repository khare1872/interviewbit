int find(vector<int>& parent,int x){
    if(parent[x]==-1) return x;
    else return parent[x]=find(parent,parent[x]);
    
}
void un(int x,int y,vector<int>& parent){
    int s1 = find(parent,x);
    int s2 = find(parent,y);
    if(s1!=s2) parent[s2]=s1;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    vector<int> parent(A.size()+1,-1);
    for(int i =0;i<C.size();i++){
        un(A[C[i][0]-1],A[C[i][1]-1],parent);
    }
    for(int i =0;i<A.size();i++){
        if(A[i]!=B[i]){
            int s1 = find(parent,A[i]);
            int s2 = find(parent,B[i]);
            if(s1!=s2) return false;
        }
    }
    return true;
}
