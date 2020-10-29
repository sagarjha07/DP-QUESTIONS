An efficient solution involves following steps.

1. Sort all array elements in increasing order. The purpose of sorting is to make sure that all divisors of an element appear before it.
2. Create an array dp[] of same size as input array. dp[i] stores size of divisible subset ending with arr[i] (In sorted array). The minimum value of dp[i] would be 1.
3. Traverse all array elements. For every element, find a divisor arr[j] with largest value of dp[j] and store the value of dp[i] as dp[j] + 1.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j])==0){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            mx=max(mx,dp[i]);
        }
        vector<int> ans;
        int prev=-1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==mx && (prev==-1 || prev%nums[i]==0)){/////---->>>>important part for output of vector
                ans.push_back(nums[i]);
                mx--;
                prev=nums[i];
            }
        }
        return ans;
    }
};