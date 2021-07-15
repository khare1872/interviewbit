class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0;
        int j = 0;
        set<pair<int,int>> s;
        s.insert({0,0});
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({nums1[0]+nums2[0],{0,0}});
        vector<vector<int>> ans;
        while(k--&&!q.empty()){
            int sum = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(s.find({i+1,j})==s.end()&&i<nums1.size()-1) {
                q.push({nums1[i+1]+nums2[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(s.find({i,j+1})==s.end()&&j<nums2.size()-1) {
                q.push({nums1[i]+nums2[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
