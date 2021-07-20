int Solution::bulbs(vector<int> &A) {
    int flag = 0;
    
    for(int i = 0; i<A.size(); i++){
        if(flag % 2 == 0){
            if(A[i] == 0) flag++;
        }
        else {
            if(A[i] == 1) flag++;
        }
    }
    
    return flag;
}
