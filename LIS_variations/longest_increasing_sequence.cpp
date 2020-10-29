#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int dp[n];
    dp[0]=1;
    int best=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<=a[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        best=max(best,dp[i]);
    }
    cout<<best<<endl;
}
