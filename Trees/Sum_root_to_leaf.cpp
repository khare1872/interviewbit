/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int &sum,int &ans){
        if(!root) {
            
            return;
        }
        sum=sum*10+root->val;
        if(!root->left&&!root->right) ans+=sum;
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);
        sum/=10;
        
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int ans = 0;
        solve(root,sum,ans);
        cout<<endl;
        return ans;
        
    }
};
