//idea is to itereate j from sum/2 to 0 and find j such that there is a subset with sum j and sum-j*2 is min where sum is sum of all elements in array
class Solution {
public:
    int solve(vector<int> arr,int n,vector<vector<int>>&dp,int start,int sum){
	    if(sum==0) return 1;
	    if(start==0) return 0;
	    if(dp[n][sum]!=-1) return dp[n][sum];
	    
	    else {
	        if(arr[start-1]>sum) return dp[start][sum]=solve(arr,n,dp,start-1,sum);
	        else return dp[start][sum]= solve(arr,n,dp,start-1,sum)||solve(arr,n,dp,start-1,sum-arr[start-1]);
	    }
	    
	}
    int Min_Difference(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
	    for(int i =0;i<n;i++){
	        sum+=arr[i];
	    }
	    for(int i=sum/2;i>=0;i--){
	    vector<vector<int>> dp(n+1,vector<int> (i+1,-1));
	    if(solve(arr,n,dp,n,i)) return abs(sum-2*i);
	    }
	    return sum;
        
    }
};
//more optimized 
int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0; i<n; i++){
	        sum += arr[i];
	    }
	    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
	    for(int i = 0; i<n+1; i++){
	        dp[i][0] = true;
	    }
	    for(int i = 1; i<n+1; i++){
	        for(int j = 1; j<sum+1; j++){
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int val;
	    for(int i = 0; i<=sum/2; i++){
	        if(dp[n][i]){val = i;}
	    }
	    return sum - 2*val;
	}
