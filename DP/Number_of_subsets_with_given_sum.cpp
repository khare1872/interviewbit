 // input -> arr of size n 
// sum

class Solution{

	public:
	long long int solve(int arr[],int n, int sum,int start, vector<vector<int>> &dp ){
	    if(sum<0||start<0)  return 0;;
	    if(sum==0) return 1;
	    
	    while(start>=0&&sum>=0){
            if(dp[start][sum]!=-1) return dp[start][sum];
            else {
                if(arr[start-1]>sum) dp[start][sum]= solve(arr,n,sum,start-1,dp)%1000000007;
                else dp[start][sum]= (solve(arr,n,sum-arr[start-1],start-1,dp)%1000000007+solve(arr,n,sum,start-1,dp)%1000000007)%1000000007;
            }
        }
        return dp[n][sum];
        
	}
	int perfectSum(int arr[], int n, int sum)
	{
        long long int res = 0;
        int start = n;
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        res = solve(arr,n,sum,start,dp);
        return res%1000000007;
	}
	  
};
