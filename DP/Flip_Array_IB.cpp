#define pii pair<int,int>
vector<vector<pii>> dp;

pii memo(const vector<int> &a,int sum,int i) {
    if(i == 0) return {sum,0};
    if(dp[sum][i].first != -1) return dp[sum][i];
    if(sum-(2*a[i-1])>=0) {
        // return <sum,items>
        pii l,r;
        l = memo(a,sum-(2*a[i-1]),i-1);
        r = memo(a,sum,i-1);
        if(l.first<r.first) {
            //l wins
            return dp[sum][i] = {l.first,1+l.second};
        }
        else if(l.first>r.first) {
            //r wins
            return dp[sum][i] = r;
        }
        else {
            if(l.second+1<=r.second) {
                // l wins
                return dp[sum][i] = {l.first,1+l.second};
            }
            else {
                // r wins
                return dp[sum][i] = r;
            }
        }
    }
    else {
        return dp[sum][i] = memo(a,sum,i-1);
    }
}

int Solution::solve(const vector<int> &a) {
    
    int sum = 0;
    for(int i : a) {
        sum += i;
    }
    dp.assign(sum+1,vector<pii>(a.size()+1,{-1,-1}));
    return memo(a,sum,a.size()).second;
}
