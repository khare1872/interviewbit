class Solution {
public:
   int coinChange(vector<int>& nums, int n) 
    {
        int m = nums.size();
        int t[m + 1][n + 1];
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(j == 0)
                    t[i][j] = 0;
                if(i == 0)
                    t[i][j] = INT_MAX - 1;
            }
        }
        
        for(int j = 1; j <= n; j++)
        {
            if(j % nums[0] == 0)
                t[1][j] = j/nums[0];
            else
                t[1][j] = INT_MAX - 1;
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(nums[i - 1] <= j)
                    t[i][j] = min(1 + t[i][j - nums[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        
        return t[m][n] == INT_MAX - 1 ? -1 : t[m][n];
      
    }  
};
