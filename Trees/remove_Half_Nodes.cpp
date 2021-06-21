/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(!A) return NULL;
    //Process left subtree
    A->left = solve(A->left);
    //Process right subtree
    A->right = solve(A->right);
    //Process root
    //if both children null return root
    //if left is null move to right and remove left
    //if right is null move to left remove right
    if(!A->left&&!A->right) return A;
    if(!A->left)  return A->right;
    if(!A->right) return A->left;
    //else return root 
    return A;
}
