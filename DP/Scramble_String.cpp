map<pair<string,string>,int> m;
int Solution::isScramble(const string s1, const string s2) {
    if(s1.compare(s2)==0) return  m[{s1,s2}] = 1;
        if(s1.length()<=1||s2.length()<=1) return  m[{s1,s2}] = 0;
        if(s1.length()!=s2.length()) return  m[{s1,s2}] = 0;
        if(m.find({s1,s2})!=m.end()) return m[{s1,s2}];
        else {
            int n = s1.length();
            for(int i=1;i<s1.length();i++){
                //Case 1 swapped
                m[{s1.substr(0,i),s2.substr(n-i,i)}] = isScramble(s1.substr(0,i),s2.substr(n-i,i));
                if(m[{s1.substr(0,i),s2.substr(n-i,i)}]){
                 m[{s1.substr(i,n-i),s2.substr(0,n-i)}] = isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
                if( m[{s1.substr(0,i),s2.substr(n-i,i)}]&& m[{s1.substr(i,n-i),s2.substr(0,n-i)}])
                    return m[{s1,s2}]= 1;
                }
                
                //Case 2 not swapped
                m[{s1.substr(0,i),s2.substr(0,i)}] = isScramble(s1.substr(0,i),s2.substr(0,i));
                    if( m[{s1.substr(0,i),s2.substr(0,i)}]){
                m[{s1.substr(i,n-i),s2.substr(i,n-i)}] = isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
                if( m[{s1.substr(0,i),s2.substr(0,i)}]&& m[{s1.substr(i,n-i),s2.substr(i,n-i)}])
                    return m[{s1,s2}]= 1;
                    }
                
            }
            return m[{s1,s2}] = 0;
        }
    
}
