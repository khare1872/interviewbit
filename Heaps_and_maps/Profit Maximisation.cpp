int Solution::solve(vector<int> &A, int B) {
int ans=0;

priority_queue<int>pq;

for(int i=0;i<A.size();i++)
pq.push(A[i]);

while(B!=0)
{
    int k = pq.top();
    pq.pop();
    ans+=k;
    k--;
    pq.push(k);
    B--;
}

return ans;
}
