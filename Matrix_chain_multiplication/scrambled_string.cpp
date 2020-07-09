unordered_map<string,bool> mp;
bool solve(string a,string b){
    if(a==b) return 1;
    if(a.size()<=1) return 0;
    string key=a;
    key+='a';
    key+=b;
    if(mp.find(key)!=mp.end()) return mp[key];
    int n=a.size();
    bool flag=false;
    for(int i=1;i<=n-1;i++){
        bool cond1=false,cond2=false;
        if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i))){
            cond1=true;
        }
        if(solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i))){
            cond2=true;
        }
        if(cond1 || cond2){
            flag=true;
            break;
        }
    }
    return mp[key]=flag;
}
int Solution::isScramble(const string A, const string B) {
    mp.clear();
    return solve(A,B);
}