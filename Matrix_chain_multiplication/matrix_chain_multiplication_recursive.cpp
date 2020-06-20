#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int matrix_chain_multiplication(int*a,int i,int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=matrix_chain_multiplication(a,i,k)+matrix_chain_multiplication(a,k+1,j)+a[i-1]*a[k]*a[j];
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<matrix_chain_multiplication(a,1,n-1)<<endl;
    }
}
