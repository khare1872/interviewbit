/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* solve(int start,int end,vector<int> &in,vector<int> &pre,int &current,int n){
        if(start>end) return NULL;
        int index=0;
        for(int i=start;i<=end;i++){
            if(in[i]==pre[current]) {
                index=i;
                break;
            }
        }
        TreeNode* node = new TreeNode(pre[current]);
        current++;
        if(start==end) return node;
            node->left=solve(start,index-1,in,pre,current,n);
            node->right=solve(index+1,end,in,pre,current,n);
        return node;
    }
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
  int current =0;
  int n = in.size();
  return solve(0,n-1,in,pre,current,n);
}
