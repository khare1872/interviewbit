void find(vector<vector<int>>&B, TreeNode* A,int level=0)
{
    if(A==NULL)return;
    if(B.size()==level)B.resize(level+1);
    B[level].push_back(A->val);
    find(B,A->left,level+1);
    find(B,A->right,level+1);
}
vector<int> Solution::solve(TreeNode* A) 
{
    vector<vector<int>>B;
    find(B,A);
    vector<int>C;
    for(int i=B.size()-1;i>=0;i--)
    {
        for (int j=0;j<B[i].size();j++)
        {
            C.push_back(B[i][j]);
        }
    }
    return C;
}
