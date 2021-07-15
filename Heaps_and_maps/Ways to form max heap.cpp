#define mod 1000000007
// vector<int> dp(32,-1);
 map<pair<int,int>,long long int> m;
 long long int choose(int n,int r){
   if(n<r) return m[{n,r}] = 0;
   if(n==r||r==0) return m[{n,r}] = 1;
   if(r==1) return m[{n,r}] = n%mod;
   if(m.find({n,r})!=m.end()) return m[{n,r}]%mod;
   else return m[{n,r}] = ((choose(n-1,r-1)%mod)+(choose(n-1,r))%mod)%mod;
 }
long long int helper(int A){
    if(A<=1) return 1;
 long long int h = log2(A);
 long long int left = (pow(2,h-1)-1+min(A-pow(2,h)+1,pow(2,h-1)));
 left%=mod;
 return (((choose(A-1,left)%mod)*(helper(left)%mod)%mod)*(helper(A-left-1)%mod))%mod;
}  
int Solution::solve(int A) {
 return helper(A)%mod;
}
