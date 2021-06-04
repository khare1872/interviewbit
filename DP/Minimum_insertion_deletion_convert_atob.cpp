int minOperations(string s1, string s2) 
	{ 
	     int x=s1.size();
        int y=s2.size();
        int dp[x+1][y+1];
        for(int i =0;i<x+1;i++) dp[i][0]=0;
        for(int i =0;i<y+1;i++) dp[0][i]=0;
        for(int i = 1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(s1[i-1]==s2[j-1]) dp[i][j]=max(1+dp[i-1][j-1],dp[i][j]);
            }
        }
        int a = dp[x][y];
        return (s1.length()+s2.length()-2*a);
	} 
