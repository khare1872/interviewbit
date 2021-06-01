class Solution {
public:
   map<pair<int,int>,int> m;
    int solve(vector<int> &nums, int target, int start ){
        if(target==0&&start==nums.size()) return 1;
        else if (start>=nums.size()) return 0;
        if(m.find({target,start})!=m.end()) return m[{target,start}];
        return m[{target,start}]= solve(nums,target-nums[start],start+1)   +  solve(nums,target+nums[start],start+1);
            }
           

        
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int start = 0;
        
        int ans = solve(nums,target,0);
        return ans;
        
    }
};
