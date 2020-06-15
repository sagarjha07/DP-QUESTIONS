#include <iostream>
using namespace std;
int count_of_subset_with_given_sum(int*a,int n,int sum){
    int dp[n+1][sum+1];
    //initialisation
    for(int i=0;i<sum+1;i++) dp[0][i]=0;
    for(int i=0;i<n+1;i++) dp[i][0]=1;
    //recursive cases
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<count_of_subset_with_given_sum(a,n,s)<<endl;
    }
}

