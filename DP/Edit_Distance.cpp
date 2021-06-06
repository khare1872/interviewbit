int t[1001][1001];
int recur(string a, string b, int m, int n){

if(m < 0)
    return n + 1;

if(n < 0)
    return m + 1;

if(t[n][m] != -1)
    return t[n][m];
if(a[m] == b[n])
    return t[n][m] = recur(a, b, m-1, n-1);
    
else{
    //m,n-1 is basically inserting a char in A that is not matching
    //m-1,n-1 is replacing the char in a with that of b;
    //m-1,n  is removing char from a
    return t[n][m] = 1 + min(recur(a, b, m, n-1), min(recur(a, b, m-1, n), recur(a, b, m-1, n-1)));
    
}
}

int Solution::minDistance(string a, string b) {
memset(t, -1, sizeof(t));
return recur(a, b, a.length()-1, b.length()-1);
}
