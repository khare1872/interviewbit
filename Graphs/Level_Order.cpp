vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<TreeNode *> frontier = {A};
    vector<vector<int>> ans;
    while (!frontier.empty()) {
        vector<TreeNode *> next;
        vector<int> temp;
        for (auto x : frontier) {
            temp.push_back(x->val);
            if (x->left) next.push_back(x->left);
            if (x->right) next.push_back(x->right);
        }
        ans.push_back(temp);
        frontier = next;
    }
    return ans;
}
