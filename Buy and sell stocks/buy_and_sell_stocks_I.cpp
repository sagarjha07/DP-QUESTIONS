int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0 ||A.size()==1) return 0;
    int profit=INT_MIN;
    int dp[A.size()+1];
    int mx=A[A.size()-1];
    dp[A.size()-1]=mx;
    for(int i=A.size()-2;i>=0;i--){
        dp[i]=mx;
        mx=max(mx,A[i]);
    }
    for(int i=0;i<A.size();i++){
        profit=max(profit,dp[i]-A[i]);
    }
    return profit;
}