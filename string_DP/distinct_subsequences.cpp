int Solution::numDistinct(string A, string B) {
    int m=A.size();
    int n=B.size();
    int dp[n+1][m+1];
    for(int i=0;i<m+1;i++) dp[0][i]=1;
    for(int i=1;i<n+1;i++) dp[i][0]=0;
   for(int i=1;i<n+1;i++){
       for(int j=1;j<m+1;j++){
           if(B[i-1]==A[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
           else dp[i][j]=dp[i][j-1];
       }
   }
    return dp[n][m];
}