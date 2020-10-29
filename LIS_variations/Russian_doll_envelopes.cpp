#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main() {
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        int x;
        int y;
        cin>>x>>y;
        a[i]={x,y};
    }
    sort(a,a+n,compare);//look at the comparator->it is different from maximum non-overlapping bridges
    
    //lis based on their south bank
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    int best=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j].second<=a[i].second){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        best=max(best,dp[i]);
    }
    cout<<best<<endl;
}