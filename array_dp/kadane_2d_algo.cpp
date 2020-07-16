class result{
    public:
    int left_bound=0;
    int right_bound=0;
    int up_bound=0;
    int down_bound=0;
    int max_sum=INT_MIN;
};
class kadane_result{
    public:
    int start;
    int end;
    int maxsum;
};
kadane_result kadane_algo(int*a,int n){
    int csum=0;
    int msum=INT_MIN;
    int cstart=0;
    int max_start;
    int max_end;
    for(int i=0;i<n;i++){
        csum+=a[i];
        if(csum<0){
            csum=0;
            cstart=i+1;
        }
        else if(csum>msum){
            msum=csum;
            max_start=cstart;
            max_end=i;
        }
    }
    kadane_result k;
    k.start=max_start;
    k.end=max_end;
    k.maxsum=msum;
    return k;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==1 && A[0].size()==1) return A[0][0];
    int temp[A.size()];
    result res;
    
    for(int l=0;l<A[0].size();l++){
        for(int i=0;i<A.size();i++){
            temp[i]=0;
        }
        for(int r=l;r<A[0].size();r++){
            for(int i=0;i<A.size();i++){
                temp[i]+=A[i][r];
            }
            kadane_result k=kadane_algo(temp,A.size());
            if(k.maxsum>res.max_sum){
                res.max_sum=k.maxsum;
                res.left_bound=l;
                res.right_bound=r;
                res.up_bound=k.start;
                res.down_bound=k.end;
            }
        }
    }
    if(res.max_sum==INT_MIN){
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                res.max_sum=max(res.max_sum,A[i][j]);
            }
        }
    }
    return res.max_sum;
}
