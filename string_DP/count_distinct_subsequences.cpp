#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    long long n=s.size();
    long long  dp[n+1];
    dp[0]=1;
    unordered_map<char,long long > mp;
    for(long long  i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(mp.find(s[i-1])!=mp.end()){
            long long  j=mp[s[i-1]];
            dp[i]=dp[i]-dp[j-1];
        }
        mp[s[i-1]]=i;
    }
    cout<<dp[n]-1<<endl;
}
