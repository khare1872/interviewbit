vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<A.size();i++)
    pq.push(make_pair(A[i][0],make_pair(0,i)));
    vector<int> v3;
    while(!pq.empty())
    {
        v3.push_back(pq.top().first);
        int i=pq.top().second.first,j=pq.top().second.second;
        pq.pop();
        if(i<A[j].size()-1)
        {
            i++;
            pq.push(make_pair(A[j][i],make_pair(i,j)));        
        }
    }
    return v3;
}
//GFG SOLUTION
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {   
        int n = arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i =0;i<K;i++){
            pq.push({arr[i][0],i*n});
        }
        
        vector<int> ans;
        while(!pq.empty()){
            pair<int,int> current = pq.top();
            pq.pop();
            ans.push_back(current.first);
            int i = current.second;
           // cout<<i<<endl;
            int index = i%n;
            if(index<K-1){
                int row_num = i/n;
                pq.push({arr[row_num][index+1],(row_num*n+index+1)});
            }
        }
        return ans;
    }
};
