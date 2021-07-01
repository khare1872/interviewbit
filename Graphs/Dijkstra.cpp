//input times = [[start,end,weight]..................]
//n = No of nodes.
//k = source node.
int Dijkstra_implementation(vector<vector<int>>& times, int n, int k) {
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
        distance[k]=0;
        pq.push({k,0});
        
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
  /* depends on Question */
//         int ans = 0;
//         for(int i =1;i<=n;i++){
//             if(distance[i]==INT_MAX) return -1;
//             else ans=max(ans,distance[i]);
//         }
//         return ans;
        
    }
