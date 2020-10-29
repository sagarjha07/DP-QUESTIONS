#include <iostream>
using namespace std;
bool same_subset_sum(int*a,int n,int sum){
    bool dp[n+1][sum+1];
    //initialisation
    for(int i=0;i<sum+1;i++) dp[0][i]=false;
    for(int i=0;i<n+1;i++) dp[i][0]=true;
    //recursive cases
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
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
        int n;
        cin>>n;
        int a[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        //if the total sum of the arr elements is odd ,we can't break the sum in two partition
        if(sum%2!=0){
            cout<<"NO"<<endl;
        }
        // now if the sum is even then there is a possibility
        else{
        bool ans=same_subset_sum(a,n,sum/2);
        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    }
}
