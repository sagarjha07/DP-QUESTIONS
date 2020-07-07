int Solution::isMatch(const string A, const string B) {
    int n=A.size();
    int m=B.size();
    bool dp[n+1][m+1];
    dp[0][0]=true;
    for(int i=1;i<n+1;i++){
        dp[i][0]=false;
    }
    for(int j=1;j<m+1;j++){
        if(B[j-1]=='*') dp[0][j]=dp[0][j-2];
        else dp[0][j]=false;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(A[i-1]==B[j-1] || B[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                if(A[i-1]==B[j-2] || B[j-2]=='.'){
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                }
            }
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}