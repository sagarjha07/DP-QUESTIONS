int Solution::canJump(vector<int> &A) {
    if(A.size()==1) return 1;
    int reachable=0;
    for(int i=0;i<A.size();i++){
        if(reachable<i) return 0;
        reachable=max(reachable,i+A[i]);
    }
    return 1;
}
