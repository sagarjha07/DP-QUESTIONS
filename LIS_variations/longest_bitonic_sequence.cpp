int lbs(vector<int> v){
    if(v.size()==0) return 0;
    if(v.size()==1) return 1;
    vector<int> dp1(v.size(),1);
    vector<int> dp2(v.size(),1);
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
    }
    reverse(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                dp2[i]=max(dp2[i],1+dp2[j]);
            }
        }
    }
    reverse(dp2.begin(),dp2.end());
    int best=INT_MIN;
    for(int i=0;i<v.size();i++){
        best=max(best,dp1[i]+dp2[i]-1);
    }
    return best;
}