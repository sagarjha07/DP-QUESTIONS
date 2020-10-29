class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        if(num==0){
            v[0]=0;
            return v;
        }
        v[0]=0;
        v[1]=1;
        for(int i=2;i<=num;i++){
            if(i%2==0){
                v[i]=v[i/2];
            }
            else v[i]=v[i/2]+1;
        }
        return v;
    }
};