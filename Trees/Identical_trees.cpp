int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL&&B==NULL) return 1;
    else if(A==NULL||B==NULL) return 0;
    //if(A!=B) return false;
    if(A->val==B->val){
    if(isSameTree(A->left,B->left)&&isSameTree(A->right,B->right)) return true;
    return false;
    }
    return false;
}
