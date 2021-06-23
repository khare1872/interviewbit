vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<A.size();i++)
    pq.push(make_pair(A[i][0],make_pair(0,i)));
    vector<int> v3;
    while(!pq.empty())
    {
        v3.push_back(pq.top().first);
        int i=pq.top().second.first,j=pq.top().second.second;
        pq.pop();
        if(i<A[j].size()-1)
        {
            i++;
            pq.push(make_pair(A[j][i],make_pair(i,j)));        
        }
    }
    return v3;
}
