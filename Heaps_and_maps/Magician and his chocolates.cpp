int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> pq;
    for(int i = 0;i<B.size();i++){
        pq.push(B[i]);
    }
    long long int ans =0;
    while(A){
        int current = pq.top();
        pq.pop();
        ans+=current;
        //cout<<ans<<" ";
        A--;
        pq.push(current/2);
    }
    return ans%1000000007;
}
