int Solution::longestValidParentheses(string A) {
    if(A.size()<=1) return 0;
    stack<int> s;
    s.push(-1);
    int ans=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            s.push(i);
        }
        else{
            s.pop();
            if(!s.empty()){
                ans=max(ans,i-s.top());
            }
            else s.push(i);
        }
    }
    if(ans==INT_MIN) return 0; 
    return ans;
}
