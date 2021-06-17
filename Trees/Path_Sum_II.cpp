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
    vector<vector<int>> ans;
    void solve(TreeNode* root,int sum,vector<int> &res){
        if(!root) {
            return;
        }
        if(root->left==NULL&&root->right==NULL&&sum==root->val){
            res.push_back(root->val);
            ans.push_back(res);
            res.pop_back();
        }
        else {
                res.push_back(root->val);
                solve(root->left,sum-root->val,res);
                solve(root->right,sum-root->val,res);
                res.pop_back();
            }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        solve(root,targetSum,res);
        return ans;
        
    }
};
