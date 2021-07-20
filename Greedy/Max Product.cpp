int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
        long long int a = A[A.size()-1]*A[A.size()-2]*A[A.size()-3];
        long long int b = A[0]*A[1]*A[A.size()-1];
    return max(a,b);
}
