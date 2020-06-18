#include <iostream>
using namespace std;
int coin_change_max_ways(int*val,int n,int w){
    int dp[n+1][w+1];
    for(int i=0;i<w+1;i++) dp[0][i]=0;
    for(int i=0;i<n+1;i++) dp[i][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(val[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i][j-val[i-1]];
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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int val;
        cin>>val;
        cout<<coin_change_max_ways(a,n,val)<<endl;
    }
}
