#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<int,int> > > &g, int u, int v, int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

void primsMst(vector<vector<pair<int,int>>> &g, int vertices){
    priority_queue< pair<int,int>>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    int src = 0;
    vector<int> key(vertices, MAX_INT);
    vector<int> parent(vertices,-1);
    vector<int> inMST(vertices,false);
    pq.push({0,src});
    key[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for(auto x : g[u]){
            int v = x.first;
            int w = x.second;
            if(inMST[v] == false && key[v] > w){
                key[v] = w;
                pq.push({key[v],v});
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<vertices;++i){
        cout<<parent[i]<<" "<<i<<endl;
    }
    int costOfMST = 0;
    for(int i=1;i<vertices;i++){
        costOfMST += g[parent[i]][i];
    }
    cout<<"MST weight : "<<costOfMST<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        int vertices;cin>>vertices;
        vector<vector<pair<int,int>> g(vertices);
        int edges;cin>>edges;
        for(int i=0;i<n;i++){
            int u,v,w;cin>>u>>v>>w;
            addEdge(g, u, v, w);
        }
        primsMST(g, vertices);
    }
    return 0;
}
