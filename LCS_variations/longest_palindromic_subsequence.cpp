#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int lps(string s1,string s2,int a,int b){
    int dp[a+1][b+1];
    for(int i=0;i<a+1;i++) dp[i][0]=0;
    for(int i=0;i<b+1;i++) dp[0][i]=0;
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
   return dp[a][b];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string str1;
        cin>>str1;
        string str2=str1;
        reverse(str2.begin(),str2.end());
        int a=str1.size();
        int b=str2.size();
        cout<<lps(str1,str2,a,b)<<endl;
    }
}
