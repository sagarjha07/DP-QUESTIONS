class Solution {
public:
    bool compare( vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        if(n==0) return 0;
        int dp[n];
        int best=0;
        for(int i=0;i<n;i++) dp[i]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][1]<envelopes[i][1] && envelopes[i][0]>envelopes[j][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            best=max(best,dp[i]);
        }
        return best;
    }
};