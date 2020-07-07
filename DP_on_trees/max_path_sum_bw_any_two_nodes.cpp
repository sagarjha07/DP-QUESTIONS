int solve(TreeNode*root,int &res){
    if(root==NULL) return 0;
    int lf=solve(root->left,res);
    int rf=solve(root->right,res);
    int temp=max(max(lf,rf)+root->val,root->val);
    int ans=max(temp,lf+rf+root->val);
    res=max(res,ans);
    return temp;
}
int Solution::maxPathSum(TreeNode* A) {
    int res=INT_MIN;
    solve(A,res);
    return res;
}