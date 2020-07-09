bool ispalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int Solution::minCut(string A) {
    if(A.size()==0) return 0;
    int dp[A.size()+1];
    for(int i=0;i<=A.size();i++) dp[i]=INT_MAX;
    dp[A.size()-1]=0;
    dp[A.size()]=0;
    for(int i=A.size()-2;i>=0;i--){
        for(int j=i;j<A.size();j++){
            if(ispalindrome(A,i,j)){
                if(j==A.size()-1){
                    dp[i]=0;
                    break;
                }
                int x=1+dp[j+1];
                if(x<dp[i]){
                    dp[i]=x;
                }
            }
        }
    }
    return dp[0];
}
