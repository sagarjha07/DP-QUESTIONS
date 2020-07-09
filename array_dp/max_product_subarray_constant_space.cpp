int Solution::maxProduct(const vector<int> &A) {
    int cur_maxprod=A[0];
    int cur_minprod=A[0];
    int prev_maxprod=A[0];
    int prev_minprod=A[0];
    int ans=A[0];
    for(int i=1;i<A.size();i++){
        cur_maxprod=max(prev_maxprod*A[i],max(prev_minprod*A[i],A[i]));
        cur_minprod=min(prev_maxprod*A[i],min(prev_minprod*A[i],A[i]));
        if(ans<cur_maxprod) ans=cur_maxprod;
        prev_maxprod=cur_maxprod;
        prev_minprod=cur_minprod;
    }
    return ans;
}