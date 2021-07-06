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
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parent(isConnected.size(),-1);
        for(int i =0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected.size();j++){
                if(isConnected[i][j]==1) un(i,j,parent);
            }
        }
        int ans =0;
        for(int i =0;i<isConnected.size();i++) if(i==find(parent,i)) ans++;
        return ans;
    }
};
