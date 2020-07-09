int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int dp[n][m];
    dp[0][0]=A[0][0];
    for(int i=1;i<m;i++) dp[0][i]=dp[0][i-1]+A[0][i];
    for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+A[i][0];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+A[i][j];
        }
    }
    return dp[n-1][m-1];
}
