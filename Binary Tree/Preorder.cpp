struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

void PreorderTraversal(TreeNode * root){
    if(root == NULL){
        return;
    }
    cout<<root->data;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}