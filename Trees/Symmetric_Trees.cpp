/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isSymmetricTree(TreeNode* A,TreeNode* B){
     if(A==NULL&&B==NULL) return 1;
    else if(A==NULL||B==NULL) return 0;
    //if(A!=B) return false;
    if(A->val==B->val){
    if(isSymmetricTree(A->right,B->left)&&isSymmetricTree(A->left,B->right)) return true;
    return false;
    }
    return false;
 }
int Solution::isSymmetric(TreeNode* A) {
    return isSymmetricTree(A,A);
}
