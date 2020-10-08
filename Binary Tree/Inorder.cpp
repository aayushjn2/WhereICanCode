struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

void InorderTraversal(TreeNode * root){
    if(root == NULL){
        return;
    }
    InorderTraversal(root->left);
    cout<<root->data;
    InorderTraversal(root->right);
}
