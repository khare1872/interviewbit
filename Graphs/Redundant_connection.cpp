class Solution {
public:
    int find(vector<int>& parent,int x){
    if(parent[x]==-1) return x;
    else return parent[x]=find(parent,parent[x]);
    
}
void un(int x,int y,vector<int>& parent){
    int s1 = find(parent,x);
    int s2 = find(parent,y);
    if(s1!=s2) parent[s2]=s1;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,-1);
        for(int i =0;i<edges.size();i++){
             int s1 = find(parent,edges[i][0]);
            int s2 = find(parent,edges[i][1]);
            if(s1==s2) return {edges[i][0],edges[i][1]};
        
             un(edges[i][0],edges[i][1],parent);
        }

        return {-1,-1};
    }
};
