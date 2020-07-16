int go (auto &A,int i,int* dp){
    if(i>=A[0].size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int sum=0;
    int first=max(A[0][i],A[1][i])+go(A,i+2,dp);
    int second=go(A,i+1,dp);
    sum+=max(first,second);
    return dp[i]=sum;
}
int Solution::adjacent(vector<vector<int> > &A) {
    int dp[A[0].size()+1];
    memset(dp,-1,sizeof(dp));
    return go(A,0,dp);
}
