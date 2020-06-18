#include <iostream>
using namespace std;
int rod_cutting(int*val,int*wt,int n,int w){
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
        int n;
        cin>>n;
        int len=n;
        int val[n],length[n];
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) length[i]=i+1;
        cout<<rod_cutting(val,length,n,len)<<endl;
    }
}
