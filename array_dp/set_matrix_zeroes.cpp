void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool rowflag=false;
    bool colflag=false;
    for(int i=0;i<A.size();i++){
     for(int j=0;j<A[0].size();j++){
         if(i==0 && A[i][j]==0) rowflag=true;
         if(j==0 && A[i][j]==0) colflag=true;
         if(A[i][j]==0){
             A[0][j]=0;
             A[i][0]=0;
         }
     }   
    }
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            if(A[0][j]==0 || A[i][0]==0){
                A[i][j]=0;
            }
        }
    }
    if(rowflag==true){
        for(int i=0;i<A[0].size();i++) A[0][i]=0;
    }
    if(colflag==true){
        for(int i=0;i<A.size();i++){
            A[i][0]=0;
        }
    }
    
}

