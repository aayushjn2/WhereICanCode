//method 1
struct TreeNode{
    int data;
    struct TreeNode* left = NULL;
    struct TreeNode* right = NULL;
};
vector<int> topView(TreeNode * root){
    if(root == NULL){
        return vector<int>();
    }
    map<int,int> m;

    m[0] = root->data;

    queue< pair<TreeNode*,int> > q;

    q.push({root,0});
    
    while(!q.empty()){
        pair<TreeNode*,int> front = q.front();
        q.pop();
        if(m[front.second]!=0){
            m[front.second] = front.first->data;
        }
        q.push({front.first->left, front.second-1});
        q.push({front.first->right, front.second +1 });
    }
    vector<int> res;
    for(auto x : map){
        res.push_back(x.second);
    }
    return res;
}
//method 2

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void topView(struct Node *root)
{
    if(root == NULL){
        return;
    }
    map<int,int> mem;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int> front = q.front();
        q.pop();
        if(mem.find(front.second) == mem.end()){
            mem[front.second] = front.first->data;
        }
        if(front.first->left)
            q.push({front.first->left,front.second - 1});
        if(front.first->right){
            q.push({front.first->right, front.second + 1});
        }
    }
    for(auto element : mem){
        cout<<element.second<<" ";
    }
}