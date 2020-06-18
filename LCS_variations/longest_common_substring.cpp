#include <iostream>
#include<climits>
using namespace std;
int lcsubstring(string s1,string s2,int a,int b){
    int dp[a+1][b+1];
    for(int i=0;i<a+1;i++) dp[i][0]=0;
    for(int i=0;i<b+1;i++) dp[0][i]=0;
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];;
            }
            else {
                dp[i][j]=0;
            }
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<a+1;i++){
        for(int j=0;j<b+1;j++){
            mx=max(mx,dp[i][j]);
        }
    }
    return mx;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        string str1,str2;
        cin>>str1>>str2;
        cout<<lcsubsting(str1,str2,a,b)<<endl;
    }
}
