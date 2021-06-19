/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* solve(int start,int end, vector<int> &A){
     if(start>end) return NULL;
     int i = max_element(A.begin()+start,A.begin()+end+1)-A.begin();
     TreeNode* node = new TreeNode(A[i]);
     node->left = solve(start,i-1,A);
     node->right = solve(i+1,end,A);
     return node;
 }
TreeNode* Solution::buildTree(vector<int> &A) {
    return solve(0,A.size()-1,A);
}
