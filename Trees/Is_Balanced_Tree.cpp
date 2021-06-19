int height(Node* root){
    if(!root) return 0;
    else return max(height(root->left),height(root->right))+1;
}
bool isBalanced(Node *A)
{
   if(!A) return true;
   if(abs(height(A->left)-height(A->right))>1) return false;
    //else if(!A->left&&!A->right) return 1;
    //else if(!A->right&&A->left&&(!A->left->left||!A->left->right)) return 1;
    else if(!A->right&&A->left&&(A->left->left||A->left->right)) return false;
    //else if(A->right&&!A->left&&(!A->right->right||!A->right->left)) return 1;
    else if(A->right&&!A->left&&(A->right->right||A->right->left)) return false;
    else return(isBalanced(A->left)&&isBalanced(A->right));
}
