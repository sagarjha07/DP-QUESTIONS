#include <bits/stdc++.h>
using namespace std;
int minimum_sum_partition(int*a,int n,int sum){
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
    vector<int> subset_sum;
    for(int i=0;i<sum+1;i++){
        if(dp[n][i]==true){
            subset_sum.push_back(i);
        }
    }
    int min_diff=INT_MAX;
    for(int i=0;i<subset_sum.size();i++){
        int diff=abs(sum-2*subset_sum[i]);
        min_diff=min(diff,min_diff);
    }
    return min_diff;
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
        //range of the values of the subset_sum=[0,sum]
        // we have to mimimise s2-s1;
        //and we know that s1+s2=sum;
        //therefore,we have to minimise (sum-2*s1)
        cout<<minimum_sum_partition(a,n,sum)<<endl;
    }
}

