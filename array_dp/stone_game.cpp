class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &A,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int val1=A[i]+min(solve(A,i+2,j),solve(A,i+1,j-1));
        int val2=A[j]+min(solve(A,i+1,j-1),solve(A,i,j-2));
        return dp[i][j]=max(val1,val2);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        solve(piles,0,piles.size()-1);
        int n=piles.size();
        int rem=sum-dp[0][n-1];
        if(rem>dp[0][n-1]) return false;
        return true;
    }
};