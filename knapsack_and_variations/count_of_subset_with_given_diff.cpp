#include <bits/stdc++.h>
using namespace std;
int count_of_subsets_with_given_diff(int*a,int n,int sum){
    int dp[n+1][sum+1];
    //initialisation
    for(int i=0;i<sum+1;i++) dp[0][i]=0;
    for(int i=0;i<n+1;i++) dp[i][0]=1;
    //recursive cases
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
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
        int n,diff;
        cin>>n>>diff;
        int a[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        // we have to find s1-s2=diif
        // we know that s1+s2=sum
        // therefore,we have to find the number of subsets with given value of s1
        // which is equal to (diff+sum)/2;
        int s1=(diff+sum)/2;
        cout<<count_of_subsets_with_given_diff(a,n,s1)<<endl;
    }
}

