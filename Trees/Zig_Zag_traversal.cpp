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
    void solve(TreeNode* root,int level,vector<vector<int>> &v){
        if(!root) return;
        else {
            if(v.size()==level) v.push_back({root->val});
            
            else {
                if(level%2==0) 
                   v[level].push_back(root->val);
                else 
                    v[level].insert(v[level].begin(),root->val);
            }
                
                solve(root->left,level+1,v);
                solve(root->right,level+1,v);

    }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        solve(root,0,v);
        return v;
        
    }
};
