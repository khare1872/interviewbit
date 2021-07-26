#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int;
int partition(vector<int>& v,int start,int end){
	int piv = v[end];
	int current = start;
	int j = current;
	while(j<end){
		if(v[j]<piv){
			swap(v[current],v[j]);
			current++;
		}
		j++;
	}
	swap(v[current],v[end]);
	return current;
}

void quicksort(vector<int>& v,int start,int end){
   if(start>end) return;
   else{
   	int mid = partition(v,start,end);
   	quicksort(v,start,mid-1);
   	quicksort(v,mid+1,end);
   }
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0;i<n;i++) cin>>v[i];
	quicksort(v,0,n-1);
    for(int i =0;i<n;i++) cout<<v[i]<<" ";
	
	return 0;
}