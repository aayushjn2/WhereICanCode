#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int>>> &g, int u, int v, int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

int cal(vector<int> x, vector<int> y,int d){
    int res  = 0;
    for(int i = 0; i < d;i++){
        res = res + abs(x[i]-y[i]);
    }
    return res;
}

void primsMST(vector<vector<pair<int,int>>> &g, int vertices){
    priority_queue< pair<int,int>, vector<pair<int,int>> > pq;
    int src = 0;
    vector<int> key(vertices, INT_MIN);
    vector<int> parent(vertices,-1);
    vector<int> inMST(vertices,false);
    pq.push({0,src});
    key[src] = 0;
    int costOfMST = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u] == false){
            costOfMST = costOfMST + pq.top().first;
        }
        inMST[u] = true;
        for(auto x : g[u]){
            int v = x.first;
            int w = x.second;
            if(inMST[v] == false && key[v] < w){
                key[v] = w;
                pq.push({key[v],v});
                parent[v] = u;
            }
        }
    }
    cout<<costOfMST<<endl;
}

int main(){
    int n,d;cin>>n>>d;
    vector<vector<pair<int,int>>> g(n);
    vector<vector<int>> points(n, vector<int>(d));
    for(int i = 0; i<n;i++){
        for(int j = 0;j<d;j++){
            cin>>points[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0; j<n; j++){
            int w = cal(points[i], points[j], d);
            addEdge(g, i, j, w);
        }
    }
    primsMST(g, n);
    return 0;
}
