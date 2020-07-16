#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int left=0,right=0;
        int max_len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else right++;
            if(left==right){
                max_len=max(max_len,2*right);
            }
            if(right>left){
                right=0;
                left=0;
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') left++;
            else right++;
            if(left==right){
                max_len=max(max_len,2*left);
        }
        if(left>right){
            right=0;
            left=0;
        }
    }
    cout<<max_len<<endl;
    }
    
}
