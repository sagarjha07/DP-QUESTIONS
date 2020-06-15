#include <iostream>
using namespace std;
int knapsack_0_1(int*val,int*a,int n,int w){
    int dp[n+1][w+1];
    // initialisation
    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int i=0;i<w+1;i++) dp[0][i]=0;
    //recursive cases in interative manner
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
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
        int val[n];
        int a[n];
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<knapsack_0_1(val,a,n,w)<<endl;
    }
}
