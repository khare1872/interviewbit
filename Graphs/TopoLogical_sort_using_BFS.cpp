class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i = 0;i<V;i++){
	       for(auto j:adj[i]) indegree[j]++; 
	    }
	    queue<int> q;
	    for(int i =0;i<V;i++){
	        if(!indegree[i]) q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int current = q.front();
	        q.pop();
	        ans.push_back(current);
	        for(auto i:adj[current]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    return ans;
	}
};
