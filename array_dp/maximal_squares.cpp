class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int n=matrix.size();
         if(n==0) return 0;
        int m=matrix[0].size();
        if(m==0) return 0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i]-'0';
        for(int i=0;i<n;i++) dp[i][0]=matrix[i][0]-'0';
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='0') dp[i][j]=0;
                else if(matrix[i][j]=='1'){
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};