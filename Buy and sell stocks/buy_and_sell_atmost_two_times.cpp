class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1) return 0;
        vector<int> dpl(n,0);// max_profit if sold upto today
        vector<int> dpr(n,0);// max profit if bougt upto today and then sold afterwards
        int lsf=prices[0];
        for(int i=1;i<n;i++){
            lsf=min(lsf,prices[i]);
            int mpist=prices[i]-lsf;
            dpl[i]=max(dpl[i-1],mpist);
        }
        int msf=prices[n-1];
        for(int i=n-2;i>=0;i--){
            msf=max(msf,prices[i]);
            int mpibt=msf-prices[i];
            dpr[i]=max(dpr[i+1],mpibt);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dpl[i]+dpr[i]);
        }
        return ans;
    }
};
