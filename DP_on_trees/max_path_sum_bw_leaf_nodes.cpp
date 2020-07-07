int solve(Node*root,int &res){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return root->data; // optional
    int lf=solve(root->left,res);
    int rf=solve(root->right,res);
    int temp=max(lf,rf)+root->data;
    if(root->left && root->right!=NULL){
        res=max(res,lf+rf+root->data);
        return temp;
    }
    else if(root->left==NULL) return rf+root->data;
    else return lf+root->data;
}
int maxPathSum(Node* root)
{ 
    int res=INT_MIN;
    solve(root,res);
    return res;
}