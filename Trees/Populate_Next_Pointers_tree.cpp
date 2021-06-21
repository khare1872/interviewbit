void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()){
    TreeLinkNode* prev = NULL;
    int n = q.size();
    while(n--){
        TreeLinkNode* current = q.front();
        q.pop();
        current->next = prev;
        prev = current;
        if(current->right) q.push(current->right);
        if(current->left) q.push(current->left);
        
    }
    }
    
}
