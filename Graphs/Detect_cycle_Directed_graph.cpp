bool helper(vector<int>adj[],unordered_set<int>&vis,unordered_set<int>&path,int node)
{
    vis.insert(node);
    path.insert(node);
    for(auto it:adj[node])
    {
        if(vis.find(it)==vis.end())
        {
            if(helper(adj,vis,path,it))
            {
                return true;
            }
        }
        else if(path.find(it)!=path.end())
        {
            return true;
        }
    }
    path.erase(node);
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int>adj[A+1];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    unordered_set<int>vis,path;
    for(int i=1;i<=A;i++)
    {
        if(vis.find(i)==vis.end())
        {
            if(helper(adj,vis,path,i))
            {
                return true;
            }
        }
    }
    return false;
}
