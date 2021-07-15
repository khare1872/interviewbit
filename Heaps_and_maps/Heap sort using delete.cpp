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
void deletenode(vector<int>& v,int i){
    swap(v[v.size()-1],v[i-1]);
    cout<<v[v.size()-1]<<" ";
    v.pop_back();
    int j = 2*i;
    while(j<=v.size()){
        if(j<v.size()&&v[j]>v[j-1]) j++;
        if(v[j-1]>v[i-1]){
            swap(v[j-1],v[i-1]);
            i=j;
            j=2*j;
        }
        else break;
    }
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
    cout<<endl<<"Heap sort using delete: ";
    for(int i =0;i<v.size();) {
        deletenode(v,1);
    }
    
    return 0;
}
