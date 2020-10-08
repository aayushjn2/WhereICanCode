struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

void LevelTraversal(TreeNode * root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<< " ";
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
    }
    return;
}
