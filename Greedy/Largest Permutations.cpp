vector<int> Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    for(int i = 0;i<A.size();i++){              
        m[A[i]]=i;
    }
    int n = A.size();
    int i = 0;
    while(i<n&&B>0){
        if(A[i]!=n-i){
            int temp = A[i];
            swap(A[i],    A[m[n-i]]);
            m[temp]=m[n-i];
            m[n-i]=i;
            B--;
        }
        i++;
    }
    return A;
}
