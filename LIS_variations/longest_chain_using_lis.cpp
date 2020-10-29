    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0 || n==1 ) return n;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }