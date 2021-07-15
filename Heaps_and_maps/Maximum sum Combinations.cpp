void find(vector<int>A,vector<int>B,vector<int> &ans,int count)
{
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	priority_queue<pair<int,pair<int,int>>> pq;
	set<pair<int,int>> s;
	
	s.insert(make_pair(A.size()-1,B.size()-1));
	pq.push(make_pair(A[A.size()-1]+B[B.size()-1],make_pair(A.size()-1,B.size()-1)));
	
	for(int c=0;c<count;c++)
	{
		pair<int,pair<int,int>> temp = pq.top();
		ans.push_back(temp.first);
		pq.pop();
		
		int i = temp.second.first;
		int j = temp.second.second;
		
		//i-1,j
		int sum = A[i-1] + B[j];
		pair<int,int> p = make_pair(i-1,j);
		if(s.find(p) == s.end())
		{
			s.insert(p);
			pq.push(make_pair(sum,p));
		}
		
		//i,j-1;
		sum = A[i] + B[j-1];
		p = make_pair(i,j-1);
		if(s.find(p) == s.end())
		{
			s.insert(p);
			pq.push(make_pair(sum,p));
		}
	}
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    vector<int> ans;
    find(A,B,ans,C);
    return ans;
}
