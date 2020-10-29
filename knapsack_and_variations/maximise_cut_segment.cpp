#include<bits/stdc++.h>
using namespace std;
int dp[40005];
int cut(int n,int x,int y,int z){
    if(n==0) return 0;
    // if(n<x && n<y && n<z) return 0;
    if(dp[n]!=-1) return dp[n];
    int op1,op2,op3;
    op1=op2=op3=INT_MIN;
    if(n-x>=0){
        op1=cut(n-x,x,y,z);
    }
    if(n-y>=0){
        op2=cut(n-y,x,y,z);
    }
    if(n-z>=0){
        op3=cut(n-z,x,y,z);
    }
    return dp[n]=max({op1,op2,op3})+1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y,z;
        cin>>x>>y>>z;
        memset(dp,-1,sizeof(dp));
        cout<<cut(n,x,y,z)<<endl;
    }
}