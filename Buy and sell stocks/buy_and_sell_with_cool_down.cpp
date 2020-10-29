class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int bsp=0-prices[0];
        int ssp=0;
        int cool=0;
        for(int i=1;i<prices.size();i++){
            int nbsp=max(bsp,cool-prices[i]);
            int nssp=max(ssp,bsp+prices[i]);
            int ncool=max(cool,ssp);
            bsp=nbsp;
            ssp=nssp;
            cool=ncool;
        }
        return ssp;
    }
};