struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void DiagonalView(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    map< pair<int, vector<int> > memory;
    while(!q.empty()){
        memory[q.front().second].push_back(q.front().first->data);
        if(q.front()->left)
            q.push({q.front()->left,q.front().second+1});
        if(q.front()->right){
            q.push({q.front()->right,q.front().second});
        }
        q.pop();
    }
    for(auto x : memory){
        for(auto val : x.second){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
    return;
}