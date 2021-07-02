int Solution::fibsum(int k) {
     vector<long long int> v(50,1);
        for(int i =2;i<50;i++) v[i]=v[i-1]+v[i-2];
        int count = 0;
        while(k>0){
           int i = upper_bound(v.begin(),v.end(),k) - v.begin();
            k-=v[i-1];
            count++;
        }
        return count;
}
