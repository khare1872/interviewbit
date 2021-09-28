int Solution::solve(int A, vector<int> &B) {
    vector<int> sum = B;
    for(int i = 1;i<A;i++){
        sum[i]+=sum[i-1];
    }
    if(sum[A-1]%3!=0) return 0;
    else {
        int firstThird = sum[A-1]/3;
        int secondThird = 2*firstThird;
        int firstThirdSoFar = 0;
        int ans=0;
        for(int i =0;i<A-1;i++){
            if(sum[i]==secondThird) ans+=firstThirdSoFar;
            if(sum[i]==firstThird) firstThirdSoFar++;
            
        }
        return ans;
    }
}
