/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(int start,int end,vector<int> &in,vector<int> &post,int &current,int n){
        if(start>end) return NULL;
        int index=0;
        for(int i=start;i<=end;i++){
            if(in[i]==post[current]) {
                index=i;
                break;
            }
        }
        TreeNode* node = new TreeNode(post[current]);
        current--;
        if(start==end) return node;
        node->right=solve(index+1,end,in,post,current,n);
            node->left=solve(start,index-1,in,post,current,n);
            
        return node;
    }
TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
  int current =post.size()-1;
  int n = in.size();
  return solve(0,n-1,in,post,current,n);
}
