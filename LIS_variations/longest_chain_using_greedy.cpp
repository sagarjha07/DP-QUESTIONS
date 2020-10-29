Consider pairs as jobs, with [start time, end time],
Then the problem is converted to ask the maximum jobs we can accomplish.

class Solution {
public:
     static bool compare(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0 || n==1 ) return n;
        sort(pairs.begin(),pairs.end(),compare);
        int last=pairs[0][1];
        int len=1;
        for(int i=1;i<n;i++){
            if(pairs[i][0]>last){
                len++;
                last=pairs[i][1];
            }
        }
        return len;
    }
};