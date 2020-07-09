int solve(vector<int> a,int b){
   int dp[b+1];
   memset(dp,0,sizeof(dp));
   dp[0]=1;
   for(int i=0;i<a.size();i++){
       for(int j=a[i];j<=b;j++){
           dp[j]=(dp[j]+dp[j-a[i]])% 1000007;
       }
   }
   return dp[b]%1000007;
}
int Solution::coinchange2(vector<int> &A, int B) {
    return solve(A,B);
}
