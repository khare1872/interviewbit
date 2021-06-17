vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(A);
    while(!st.empty()){
        TreeNode* current = st.top();
        ans.push_back(current->val);
        st.pop();
        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
    return ans;
}
