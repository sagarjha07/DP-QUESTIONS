#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
string print_lcs(string s1,string s2,int a,int b){
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
   string lcs="";
   int i=a,j=b;
   while(i>0 && j>0){
       if(s1[i-1]==s2[j-1]){
           lcs+=s1[i-1];
           i--;j--;
       }
       else{
           if(dp[i-1][j]>dp[i][j-1]){
               i--;
           }
           else j--;
       }
   }
   reverse(lcs.begin(),lcs.end());
   return lcs;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        string str1,str2;
        cin>>str1>>str2;
        cout<<print_lcs(str1,str2,a,b)<<endl;
    }
}
