struct TreeNode {
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

vector<int> leftView(TreeNode* root){
    if(root == NULL){
        return vector<int>();
    }
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        res.push_back(q.front()->data);
        while(queueSize>0){
            TreeNode * front = q.front();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            q.pop();
            queueSize--;
        }
    }
    return res;
}