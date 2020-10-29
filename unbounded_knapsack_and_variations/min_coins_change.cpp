#include <bits/stdc++.h>
using namespace std;
int knapsack_0_1(int*a,int n,int w){
    int dp[n+1][w+1];
    // initialisation
    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int i=1;i<w+1;i++) dp[0][i]=INT_MAX-1;
    //initialise first row also
    for(int i=1;i<w+1;i++){
        if(i%a[0]==0){
            dp[1][i]=1;
        }
        else dp[1][i]=0;
    }
    //recursive cases in interative manner
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][w]==INT_MAX-1) return -1;
    return dp[n][w];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>w>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<knapsack_0_1(a,n,w)<<endl;
    }
}
