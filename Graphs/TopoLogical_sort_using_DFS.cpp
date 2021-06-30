class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfstopo(int i,vector<int> & v,vector<int> & isVisited,vector<int> adj[]){
	    if(!isVisited[i]){
	        isVisited[i]=1;
	        for(int j = 0;j<adj[i].size();j++){
	            dfstopo(adj[i][j],v,isVisited,adj);
	        }
	        v.push_back(i);
	    }
	    
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> v(V);
	    vector<int> isVisited(V,0);
	    for(int i =0;i<V;i++){
	        if(!isVisited[i]){
	            dfstopo(i,v,isVisited,adj);
	        }
	    }
	    reverse(v.begin(),v.end());
	return v;
	}
	
};
