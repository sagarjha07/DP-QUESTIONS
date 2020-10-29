The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the coresponding number of these sequence which ends with nums[i], respectively. That is:

len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].

Then, the result is the sum of each cnt[i] while its corresponding len[i] is the maximum length.


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //lis variation
        vector<pair<int,int>> dp(nums.size(),{1,1});
        //dp.first for length
        //dp.second for count
        int max_len=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                    else if(dp[i].first<dp[j].first+1){
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                }
            }
            max_len=max(max_len,dp[i].first);
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            if(max_len==dp[i].first){
                ans+=dp[i].second;
            }
        }
        return ans;
    }
};