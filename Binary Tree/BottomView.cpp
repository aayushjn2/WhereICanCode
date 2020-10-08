struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

vector<int> bottomView(TreeNode * root){
    if(root == NULL){
        return vector<int>();
    }
    map<int,int> m;
    queue<TreeNode*,int> q;
    q.push({root,0});
    m[0] = root->data;
    while(!q.empty()){
        pair<TreeNode*,int> front;
        front = q.front();
        m[front.second] = front.first->data;
        q.push({front.first->left, front.second - 1});
        q.push({front.first->right, front.second + 1});
    }
    for(auto x: m){
        res.push_back(x.second);
    }
    return res;
}