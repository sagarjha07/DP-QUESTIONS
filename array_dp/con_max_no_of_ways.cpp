int solve(vector<int> a,int b){
    int dp[a.size()+1][b+1];
    dp[0][0]=1;
    for(int i=1;i<b+1;i++) dp[0][i]=0;
    for(int i=1;i<a.size()+1;i++) dp[i][0]=1;
    for(int i=1;i<a.size()+1;i++){
        for(int j=1;j<b+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=(dp[i-1][j]+dp[i][j-a[i-1]])%1000007;
            }
            else dp[i][j]=(dp[i-1][j])%1000007;
        }
    }
    return (dp[a.size()][b])%1000007;
}
int Solution::coinchange2(vector<int> &A, int B) {
    return solve(A,B);
}
