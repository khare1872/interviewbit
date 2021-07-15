vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    vector<int> ans;
    if(B>A.size()) return ans;
    int start=0;
    for(int i=0;i<B;i++) mp[A[i]]++;
    ans.push_back(mp.size());
    for(int i=B;i<A.size();i++)
    {
        mp[A[i]]++;
        if(mp[A[start]]==1) mp.erase(A[start]);
        else mp[A[start]]--;
        
        start++;
        ans.push_back(mp.size());
    }
    
    return ans;
}
