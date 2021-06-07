class Solution {
public:
   map<pair<pair<int,int>,int>,bool> m;
    bool solve(int n,int start,int required_sum,vector<int> nums,int k, vector<int> &ans){
        if(required_sum==0&&n==0) return true;
        
        if(n<=0||start>=nums.size()) return false;
        
        if(m.find({{n,required_sum},start})!=m.end()) return m[{{n,required_sum},start}];
        
        if(nums[start]*k<=required_sum){
            ans.push_back(nums[start]);
            
              m[{{n-1,required_sum-nums[start]*k},start+1}]= solve(n-1,start+1,required_sum-nums[start]*k,nums,k,ans);
              if( m[{{n-1,required_sum-nums[start]*k},start+1}]){
                  return true;
              }
            ans.pop_back();
    }
        m[{{n,required_sum},start+1}] = solve(n,start+1,required_sum,nums,k,ans);
        return  m[{{n,required_sum},start}]=m[{{n,required_sum},start+1}];
    }
    bool splitArraySameAverage(vector<int>& nums) {
        sort(nums.begin(),nums.begin());
        
        int required_sum=0;
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
            
            sum+=nums[i];
        
        int k = nums.size();
        
        for(int i=1;i<nums.size();i++){
            if((i*sum)%k!=0) continue;
            
            required_sum= i*sum;
            
            int start=0;
            
            int n=0;
            vector<int> ans;
            
            if(solve(i,start,required_sum,nums,k,ans)) {
                //sort(ans.begin(),ans.end());
                //for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
                return true;
            }
        }
        return false;
    }
};
