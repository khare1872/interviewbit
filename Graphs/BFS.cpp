class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> is_visited(V,false);
	    queue<int> bfs;
	    vector<int> ans;
	    bfs.push(0);
	    //keep record of visited array
	    is_visited[0]=true;
	    while(!bfs.empty()){
	        int current = bfs.front();
	        bfs.pop();
	        ans.push_back(current);
	        is_visited[current] = true;
	        for(int i =0;i<adj[current].size();i++){
	            //if not visited move to that array
	            if(!is_visited[adj[current][i]]){
	                is_visited[adj[current][i]] = true;
	                bfs.push(adj[current][i]);
	            }
	        }
	    }
	    return ans;
	}
};
