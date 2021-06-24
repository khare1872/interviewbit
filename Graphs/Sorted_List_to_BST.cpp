TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A)return NULL;
    if(!A->next) return new TreeNode(A->val);
    ListNode *slow = A, *fast = A, *prev;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    prev->next=nullptr;
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(slow->next);
    
    return root;
}
