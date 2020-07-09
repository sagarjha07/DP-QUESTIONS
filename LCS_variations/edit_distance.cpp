#include <iostream>
using namespace std;
int minDistance(string A,string B,int n,int m){
    int dp[n+1][m+1];
     dp[0][0]=0;
    for(int i=1;i<m+1;i++){
        dp[0][i]=1+dp[0][i-1];
    }
    for(int i=1;i<n+1;i++){
        dp[i][0]=1+dp[i-1][0];
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
            int q1=dp[i-1][j-1];
            int q2=dp[i-1][j];
            int q3=dp[i][j-1];
            int mn=min(q1,q2);
            mn=min(mn,q3);
            dp[i][j]=mn+1;
        }
        }
    }
    return dp[n][m];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        cout<<minDistance(a,b,n,m)<<endl;
    }
}
