/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> v;
 void solve(TreeNode* A){
    if(!A) return;
    solve(A->left);
    v.push_back(A->val);
    solve(A->right);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    solve(A);
    int ans  = v[B-1];
    v.clear();
    return ans;
}
