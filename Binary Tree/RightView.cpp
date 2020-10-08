struct TreeNode {
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

vector<int> rightView(TreeNode * root){
    if(root == NULL){
        return vector<int>();
    }
    queue<TreeNode*> q;
    vector<int> res;
    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        TreeNode * front;
        while(queueSize > 0){
            front = q.front();
            queueSize--;
        }
        res.push_back(front->data);
    }
    return res;
}