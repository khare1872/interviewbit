bool isSafe(vector<vector<int> > &A, int i, int j, int n, int m)
{
	if(i>=0 &&i<n && j>=0 && j<m && A[i][j]==1)
		return true;
	return false;
}
int find(vector<vector<int> > &A, int x, int y, int n, int m)
{
	queue<pair<int, int> > q;
	q.push({x,y});
	int X[]={0,0,1,-1,1,1,-1,-1};
	int Y[]={1,-1,0,0,-1,1,1,-1};
	int c=0, newX, newY, i;
	A[x][y]=0;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		c++;
		for(i=0;i<8;i++)
		{
			newX = X[i]+temp.first;
			newY = Y[i]+temp.second;
			if(isSafe(A,newX,newY,n,m))
			{
				A[newX][newY]=0;
				q.push({newX, newY});
			}
		}
	}
	return c;
}
int Solution::solve(vector<vector<int> > &A) {
    int ans=0;
	if(A.size()==0 || A[0].size()==0)
		return 0;
	int n=A.size(), m=A[0].size(), i, j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(A[i][j]==1)
			{
				int x = find(A,i,j,n,m);
				ans=max(ans, x);
			}
	return ans;
}
