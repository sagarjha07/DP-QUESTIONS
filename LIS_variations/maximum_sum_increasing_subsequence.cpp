#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int dp[n];
    dp[0]=a[0];
    int best=a[0];
    for(int i=1;i<n;i++){
        dp[i]=a[i];
        for(int j=i-1;j>=0;j--){
            if(a[j]<=a[i]){
                dp[i]=max(dp[i],a[i]+dp[j]);
            }
        }
        best=max(best,dp[i]);
    }
    cout<<best<<endl;
}
