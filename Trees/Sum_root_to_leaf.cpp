/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  void solve(TreeNode* root,int sum,int &ans){
        if(!root) {
            
            return;
        }
        sum=(sum*10+root->val)%1003;
        if(!root->left&&!root->right) ans=(ans+sum)%1003;
        else {
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);
        sum/=10;
        }
        
    }
int Solution::sumNumbers(TreeNode* root) {
    int sum =0;
    int ans =0;
    solve(root,sum,ans);
return ans;
}
