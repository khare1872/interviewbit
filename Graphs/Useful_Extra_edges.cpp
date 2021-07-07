int Dijkstra_implementation(vector<vector<int>>& times, int n, int k,int src) {
        vector<vector<pair<int,int>>> adj(n+1);
        // start to {node,weight}
        for(int i =0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        // record of distance
        vector<int> distance(n+1,INT_MAX);
        // priority queue of pair of {node,dist}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        //update dist of source to 0;
        distance[src]=0;
        pq.push({src,0});
        
        //Dijkstra's algorithm
        while(!pq.empty()){
            int current_node = pq.top().first;
            int current_distance = pq.top().second;
            pq.pop();
            for(int i =0;i<adj[current_node].size();i++){
                int dist = current_distance+adj[current_node][i].second;
                if(dist<distance[adj[current_node][i].first]) {
                    distance[adj[current_node][i].first]=dist;
                    pq.push({adj[current_node][i].first,dist});
                }
            }
        }
        return distance[k];
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    
    int ans = INT_MAX;
    for(int i =0;i<E.size();i++){
        if(E[i][0]<=A&&E[i][1]<=A){
        B.push_back({E[i][0],E[i][1],E[i][2]});
         B.push_back({E[i][1],E[i][0],E[i][2]});
         ans = min(ans,Dijkstra_implementation(B,A,D,C));
         B.pop_back();
         B.pop_back();
        }
    }
    if(ans==INT_MAX) return -1;
    else return ans;
}
