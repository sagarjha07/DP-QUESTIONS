int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    vector<int> d;
    for(int i=1;i<A.size();i++){
        int dist=max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
        d.push_back(dist);
    }
    int ans=0;
    for(int i=0;i<d.size();i++){
        ans+=d[i];
    }
    return ans;
}