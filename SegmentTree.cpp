#include <bits/stdc++.h>
using namespace std;
void buildSegmentTree(vector<int>& v,vector<int>& input,int start,int end,int treePointer){
	// base case 
	if(start==end){
		v[treePointer]=input[start];
		return;
	}
	
	int mid = start+(end-start)/2;
	//buid left segment tree
	buildSegmentTree(v,input,start,mid,2*treePointer);
	//build right segment tree
	buildSegmentTree(v,input,mid+1,end,2*treePointer+1);
	//store result in parent node let's say we need to store sum
	v[treePointer]=v[2*treePointer]+v[2*treePointer+1];

	return;
}
void updateSegmentTree(vector<int>& v,vector<int>& input,int start,int end,int treePointer, int index,int val){
    //first update the value on index first
    if(start==end) {
    	input[index]= val;
    	v[treePointer] = val;
    	return ;
    }
	int mid = start+ (end-start)/2;
    if(index>mid){
    	//go right
        updateSegmentTree(v,input,mid+1,end,2*treePointer+1,index,val);
    }
    else {
    	//go left
    	updateSegmentTree(v,input,start,mid,2*treePointer,index,val);
    }
       //update
    v[treePointer]=v[2*treePointer]+v[2*treePointer+1];
    return;
}
int query(vector<int>& v,int start,int end,int queryStart,int queryEnd,int treePointer){
     //case 1 range completely outside.
	if(start>queryEnd || end<queryStart) {
		return 0;
	}
	//case 2 range completely inside.
	else if(start>=queryStart&&end<=queryEnd){
       return v[treePointer];
	}
	//case 3 partially inside and partially outside
	else {
		//call on both trees.
		int mid = start+(end-start)/2;
		int ans1 = query(v,start,mid,queryStart,queryEnd,2*treePointer);
		int ans2 = query(v,mid+1,end,queryStart,queryEnd,2*treePointer+1);
		return ans1+ans2;
	}
}

int main(){
	vector<int> input(5) ;

	for(int i = 0;i<5;i++) input[i]=i+1;

	vector<int> v(10);

	buildSegmentTree(v,input,0,4,1);
	for(int i =1;i<10;i++){

		cout<<v[i]<<" ";
	}
    cout<<endl;
	updateSegmentTree(v,input,0,4,1,2,10);

    for(int i =1;i<10;i++){

		cout<<v[i]<<" ";
	} 
     // find sum between 2 and 4
	cout<<endl<<" Sum between 2 and 4 is "<<query(v,0,4,2,4,1);
}
