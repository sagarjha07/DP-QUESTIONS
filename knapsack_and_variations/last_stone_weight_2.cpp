class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==0) return 0;
        int sum=0;
        for(int s:stones){
            sum+=s;
        }
        bool dp[n+1][sum+1];
        for(int i=1;i<sum+1;i++) dp[0][i]=false;
        for(int i=0;i<n+1;i++) dp[i][0]=true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<sum+1;i++){
            if(dp[n][i]==true)
            mn=min(mn,abs(sum-2*i));
        }
        return mn;
    }
};