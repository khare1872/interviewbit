class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> indegree(n+1,0);
        for(int i = 0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        for(int i =1;i<n+1;i++){
            if(indegree[i]==n-1) return i;
        }
        return -1;
        
    }
};
