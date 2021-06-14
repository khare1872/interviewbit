//recurssive+memoized not suitable always
class Solution {
public:
    map<pair<string,string>,bool> m;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0) return true;
        if(s1.length()<=1||s2.length()<=1) return false;
        if(s1.length()!=s2.length()) return false;
        if(m.find({s1,s2})!=m.end()) return m[{s1,s2}];
        else {
            int n = s1.length();
            for(int i=1;i<s1.length();i++){
                //Case 1 swapped
                m[{s1.substr(0,i),s2.substr(n-i,i)}] = isScramble(s1.substr(0,i),s2.substr(n-i,i));
                m[{s1.substr(i,n-i),s2.substr(0,n-i)}] = isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
                if( m[{s1.substr(0,i),s2.substr(n-i,i)}]&& m[{s1.substr(i,n-i),s2.substr(0,n-i)}])
                    return true;
                
                //Case 2 not swapped
                m[{s1.substr(0,i),s2.substr(0,i)}] = isScramble(s1.substr(0,i),s2.substr(0,i));
                m[{s1.substr(i,n-i),s2.substr(i,n-i)}] = isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
                if( m[{s1.substr(0,i),s2.substr(0,i)}]&& m[{s1.substr(i,n-i),s2.substr(i,n-i)}])
                    return true;
                
            }
            return false;
        }
        
    }
};
