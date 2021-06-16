void solve(TreeNode* node,int d,int& count){
        if(node==NULL) return ;
        count=max(count,d);
        solve(node->left,d+1,count);
        solve(node->right,d+1,count);
    }
int Solution::maxDepth(TreeNode* A) {
    int count =0;
    solve(A,0,count);
    return count+1;
    
}
