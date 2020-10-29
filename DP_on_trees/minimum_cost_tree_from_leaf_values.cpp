class Solution {
public:
    #define ll long long
    map<pair<ll,ll>,pair<ll,ll>> dp;
    pair<ll,ll> solve(vector<int> &arr,ll s,ll e){
        if(s==e){//leaf node
           return {arr[s],0};//single node then {maxleaf value=arr[s]and minimum sum=0};
       }
        if(dp.find({s,e})!=dp.end()) return dp[{s,e}];
        ll max_leaf=INT_MIN;
        ll min_sum=INT_MAX;
        for(int i=s;i<e;i++){
            pair<ll,ll> left=solve(arr,s,i);
            pair<ll,ll> right=solve(arr,i+1,e);
            max_leaf=max(left.first,right.first);
            min_sum=min(min_sum,left.second+right.second+left.first*right.first);
        }
        return dp[{s,e}]={max_leaf,min_sum};
    }
    int mctFromLeafValues(vector<int>& arr) {
        dp.clear();
        pair<ll,ll> ans=solve(arr,0,arr.size()-1);
        return ans.second;
    }
};