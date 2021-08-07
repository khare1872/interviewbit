class Solution {
public:
    int longestValidParentheses(string s) {
        int l =0;
        int r =0;
        int i =0;
        int ans = 0;
        while(i<s.length()){
            if(s[i]=='(') l++;
            else r++;
            if(l==r) ans = max(l+r,ans);
            else if(r>l) {
                l=0;
                r=0;
            }
            i++;
        }
        i--;
        l=0;
        r=0;
        while(i>=0){
            if(s[i]=='(') l++;
            else r++;
            if(l==r) ans = max(l+r,ans);
            else if(l>r) {
                l=0;
                r=0;
            }
            i--;
        }
        return ans;
        
    }
};
