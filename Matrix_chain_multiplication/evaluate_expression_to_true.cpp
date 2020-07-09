unordered_map<string,int> mp;
int solve(string s,int i,int j,bool istrue){
    if(i>j){
        return false;
    }
    if(i==j){
        if(istrue==true){
            return s[i]=='T';
        }
        else return s[i]=='F';
    }
    string key="";
    key+=to_string(i);
    key+=' ';
    key+=to_string(j);
    key+=' ';
    key+=to_string(istrue);
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){
            int lt = solve(s,i,k-1,true);
	        int lf = solve(s,i,k-1,false);
	        int rt = solve(s,k+1,j,true);
	        int rf = solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(istrue==true){
              ans+=(lt*rt);  
            }
            else ans=ans+lf*rf+lf*rt+lt*rf;
        }
        else if(s[k]=='|'){
            if(istrue==true){
                ans=ans+(lt*rt+lf*rt+lt*rf);
            }
            else ans+=(lf*rf);
        }
        else if(s[k]=='^'){
            if(istrue==true){
                ans+=((lf*rt)+(lt*rf));
            }
            else ans+=(lt*rt+lf*rf);
        }
    }
    return mp[key]=ans%1003;
}
int Solution::cnttrue(string A) {
    mp.clear();
    return solve(A,0,A.size()-1,true);
}
