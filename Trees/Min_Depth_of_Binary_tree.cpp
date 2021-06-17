void solve(TreeNode* node,int d,int& count){
        if(node==NULL) return ;
        count=min(count,d);
        solve(node->left,d+1,count);
        solve(node->right,d+1,count);
    }
int Solution::minDepth(TreeNode* A) {
    int count =INT_MAX;
    solve(A,0,count);
    return count+1;
    
}
