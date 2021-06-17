void helper(TreeNode *A, int B, vector<int> &ans, vector<int> temp){
    if(ans.size()>0 || A==NULL)
        return;
    
    if(A->val==B){
        temp.push_back(A->val);
        ans = temp;
        return;
    }
    
    temp.push_back(A->val);
    helper(A->left,B,ans,temp);
    helper(A->right,B,ans,temp);
}

vector<int> Solution::solve(TreeNode* A, int B){
    vector<int> temp;
    vector<int> ans;
    //bool flag = false;
    helper(A,B,ans,temp);
    return ans;
}
