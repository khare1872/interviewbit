class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> isVisited(V,false);
	    vector<int> parent(V);
	    for(int i = 0;i<V;i++) parent[i]=i;
	    queue<int> q;
	    for(int j = 0;j<V;j++){
	        if(!isVisited[j]){
	        q.push(j);
	        isVisited[j]=true;
	        while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        for(auto i: adj[curr]){
	           if(isVisited[i]&&parent[curr]!=i) return true;
	           else if(!isVisited[i]) {
	               isVisited[i]=true;
	               parent[i]=curr;
	               q.push(i);
	           }
	       }
	    }
	  }
	}
	    return false;
	}
};
