vector<int> Solution::findPerm(const string A, int B) {
    int l=1;
    int r=B;
    vector<int> v;
    int i=0;
    while(l<r){
        if(A[i]=='I'){
            v.push_back(l);
            l++;
        }
        else{
            v.push_back(r);
            r--;
        }
        i++;
    }
    v.push_back(l);
    return v;
}
