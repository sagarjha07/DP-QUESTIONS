class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0) count+=1;
        }
        if(S>sum) return 0;
        if((sum+S)%2!=0) return 0;
        int a=(sum+S)/2;
        int dp[n+1][a+1];
        for(int i=0;i<a+1;i++) dp[0][i]=0;
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<a+1;j++){
                if(nums[i-1]==0) dp[i][j]=dp[i-1][j];
                else if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (pow(2,count)*dp[n][a]);
    }
};