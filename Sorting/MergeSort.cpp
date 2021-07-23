#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int;
void merge(vector<int>&v,int start,int mid,int end){
	vector<int> temp(end-start+1);
	int k = 0;
	//pointer of first array
	int i =start;
	//pointer of second array
	int j = mid+1;
	//merge both arrays and store in temp
	while(i<=mid&&j<=end){
		if(v[i]>=v[j]){
			temp[k]=v[j];
			k++;
			j++;
		}
		else {
			temp[k]=v[i];
			i++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]=v[i];
		i++;
		k++;
	}
	while(j<=end){
		temp[k]=v[j];
		j++;
		k++;
	}
	//changes in original array
	for(int i =start;i<=end;i++){
		v[i]=temp[i-start];
	}
	return ;
}
void mergesort(vector<int>& v,int start,int end){
	if(start>=end) return;
	else{
		int mid = (start+end)/2;
		mergesort(v,start,mid);
		mergesort(v,mid+1,end);
		merge(v,start,mid,end);
	}
}

int main(){

	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0;i<n;i++){
		cin>>v[i];
	}
	mergesort(v,0,v.size()-1);
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}

