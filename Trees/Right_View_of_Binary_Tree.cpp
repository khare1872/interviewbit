 void solvea(TreeNode* A,int level,vector<int>&v){
     if(!A||A->val==-1) return;
     else {
         if(v.size()==level) v.push_back(A->val);
         else v[level]=A->val;
         if(A->left!=NULL) solvea(A->left,level+1,v);
         if(A->right!=NULL)solvea(A->right,level+1,v);
     }
 }
vector<int> Solution::solve(TreeNode* A) {
    vector<int> v;
    solvea(A,0,v);
    return v;
}
