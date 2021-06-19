/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int solve(TreeNode* A,int target,unordered_set<int>& s){
     if(!A) return 0;
     if(s.find(target-A->val)!=s.end()) return 1;
     s.insert(A->val);
     return(solve(A->left,target,s)||solve(A->right,target,s));
 }
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int> s;
    return solve(A,B,s);
}
