struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

void PostorderTraversal(TreeNode * root){
    if(root == NULL){
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data;
}