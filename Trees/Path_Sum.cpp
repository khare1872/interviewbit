class Solution {
public:
    bool solve(TreeNode* root,int sum){
        if(!root) return false;
        if(root->left==NULL&&root->right==NULL&&sum-root->val==0) return true;
        
        cout<<root->val<<" ";
        return solve(root->left,sum-root->val)||solve(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,targetSum);
        
    }
};
