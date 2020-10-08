#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> & g,int u, int v){
    g[u].push_back(v);
}
void printGraph(vector<vector<int>> & g){
    for(int u=0;u<g.size();u++){
        cout<<u<<" -> ";
        for(auto v: g[u]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return;
}

void util(vector<vector<int>> &g, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap){
    static time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for(auto v : g[u]){
        if(visited[v] == false){
            children++;
            parent[v] = u;
            util(g, u, visited, disc, low, parent, ap);
            low[u] = min(low[u],low[v]);
            if(parent[u] == -1 && children > 1){
                ap[u] = true;
            }
            if(parent[u] !=-1 && low[v] >= disc[u]){
                ap[u] = true;
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u],disc[v]);
        }
    }
}
void articulationPoints(vector<vector<int>> & g, int vertices){
    vector<bool> visited(vertices, false), ap(vertices, false);
    vector<int> parent(vertices, -1), low(vertices), disc(vertices);
    for(int u=0;u<vertices;u++){
        if(visited[u]==false){
            util(g, u, visited, disc, low, parent, ap);
        }
    }
    for(int u=0;u<vertices;u++){
        if(ap[u]){
            cout<<u<<" ";
        }
    }
    return;
}
int main(){
    int t;cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<vector<int>> g(v);
        for(int i=0;i<e;i++){
            int u,v;cin>>u>>v;
            addEdge(g,u,v);
        }
        printGraph(g);
        articulationPoints(g);
    }
    return 0;
}