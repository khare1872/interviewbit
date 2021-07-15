#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& v,int i){
    //int temp = v[i-1];
    while(i<=v.size()){
        int childa = 2*i;
        int childb = 2*i+1;
        if(childa<=v.size()&&v[i-1]<v[childa-1]){
                swap(v[i-1],v[childa-1]);
                heapify(v,childa);
            }
        if(childb<=v.size()&&v[i-1]<v[childb-1]) {
                swap(v[i-1],v[childb-1]);
                heapify(v,childb);
            }
            return;
        }
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
    
    for(int i = v.size();i>0;i--) {
        heapify(v,i);
    }
    cout<<"Heapify :";
    for(int i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"Check if correctly heapified: ";
    for(int i =0;i<v.size();) {
        deletenode(v,1);
    }
    return 0;
}
