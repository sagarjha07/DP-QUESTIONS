int Solution::solve(vector<int> &A, int B) {
       int n=A.size();
        if(n<=1 || B<=0) return 0;
         if (B>= n/2 ) {
            int res = 0;
            for (int i = 1; i < n; i++) {
              if(A[i] - A[i - 1] > 0)
                res += A[i] - A[i - 1];
            }
            return res;
        }
        vector<vector<int>> dp(B+1,vector<int>(n));
        for(int i=1;i<=B;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1];
                for(int pd=0;pd<j;pd++){
                    dp[i][j]=max(dp[i][j],dp[i-1][pd]+A[j]-A[pd]);
                }
            }
        }
        return dp[B][n-1];
}
