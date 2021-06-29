class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(vector<bool> & isVisited,vector<int>& ans,int i,vector<int> adj[]){
	    if(!isVisited[i]) {
	        isVisited[i]=true;
	        ans.push_back(i);
	        for(int j = 0;j<adj[i].size();j++){
	            dfs(isVisited,ans,adj[i][j],adj);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	   vector<bool> isVisited(V,false);
	   vector<int> ans;
	   for(int i = 0;i<V;i++){
	       if(!isVisited[i]) dfs(isVisited,ans,i,adj);
  	   }
  	   return ans;
	}
};
