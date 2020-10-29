class Solution {
public:
    int dp[605][105][105];
    int count(string &s,char ch){
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch) ans+=1;
        }
        return ans;
    }
    int solve(vector<string>&s,int m,int n,int i){
        if(i==s.size() || (m==0 && n==0)) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int zeroes=count(s[i],'0');
        int ones=count(s[i],'1');
        int ans=0;
        if(zeroes<=m && ones<=n){
            int op1=1+solve(s,m-zeroes,n-ones,i+1);
            int op2=solve(s,m,n,i+1);
            ans=max(op1,op2);
        }
        else ans=solve(s,m,n,i+1);
        return dp[i][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};