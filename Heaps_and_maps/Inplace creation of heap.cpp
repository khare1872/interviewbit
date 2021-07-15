#include <bits/stdc++.h>
using namespace std;
void insert(vector<int>& v,int n){
    int temp = v[n];
    int i = n;
    while(i>0&&temp>v[i/2]){
        v[i]=v[i/2];
        i=i/2;
    }
    v[i]=temp;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    for(int i =1;i<n;i++){
        insert(v,i);
    }
    for(int i =0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}
