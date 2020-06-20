#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool ispalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}
int palindrome_partition(string s,int i,int j){
    if(i>=j) return 0;
    if(ispalindrome(s,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=palindrome_partition(s,i,k)+palindrome_partition(s,k+1,j)+1;
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<palindrome_partition(s,0,s.size()-1)<<endl;
    }
}
