vector<int> Solution::solve(int A, int B, int C, int D) {
    int i_a=0,i_b=0,i_c=0,na=A,nb=B,nc=C;
    vector<int>v(D);
    for(int i=0;i<D;i++){
       int next=min({na,nb,nc});
       v[i]=next;
       if(v[i]==na) na=A*v[i_a++];
       if(v[i]==nb) nb=B*v[i_b++];
       if(v[i]==nc) nc=C*v[i_c++];
    }
    return v;
}
