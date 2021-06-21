class Solution {
public:
    pair<int,int> findlevel( TreeNode* root, int a,int height,int &parent){
        if(!root) return {0,0};
        if(root->val==a) return {height,parent};
       // parent  = root->val;
        pair<int,int> level = findlevel(root->left,a,height+1,root->val);
        if(level.first) return level;
         return findlevel(root->right,a,height+1,root->val);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int parentx = 0;
        int parenty = 0;
       // cout<<findlevel(root,x,0,parentx)<<" "<<parentx<<" "<<findlevel(root,y,0,parenty)<<" "<
return ((findlevel(root,x,0,parentx).first==findlevel(root,y,0,parenty).first)&&findlevel(root,x,0,parentx).second!=findlevel(root,y,0,parenty).second);
    }
};
