int pow(long long a,int b,int mod){
    long long ans=1;
    while(b>0){
        if(b&1){
           ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return (int)ans%mod;
}
int ncr(int n,int r,int mod){
    if(r>n-r){
        r=n-r;
    }
    long long res=1;
    for(int i=0;i<r;i++){
        res=(res*(n-i))%mod;
        int inv=pow(i+1,mod-2,mod);
        res=(res*inv)%mod;
    }
    return (int)res%mod;
}
int Solution::chordCnt(int A) {
  int mod=1000000007;
  long long  ans=ncr(2*A,A,mod);
  int inv=pow(A+1,mod-2,mod);
  ans=(ans*inv)%mod;
  return (int)ans%mod;
}