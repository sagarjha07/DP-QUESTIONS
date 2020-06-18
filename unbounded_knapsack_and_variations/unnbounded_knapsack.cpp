#include <iostream>
using namespace std;
int unbounded_knapsack(int*val,int*wt,int n,int w){
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int i=0;i<w+1;i++) dp[0][i]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int val[n],wt[n];
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>wt[i];
        cout<<unbounded_knapsack(val,wt,n,w)<<endl;
    }
}
