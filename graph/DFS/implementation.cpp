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
void dfsUtility(vector<vector<int>>& g,vector<bool> & vis, int u ){
    cout<<u<<" ";
    for(auto v: g[u]){
        if(vis[v] == false){
            vis[v] = true;
            dfsUtility(g,vis,v);
        }
    }

}
void dfs(vector<vector<int>> & g){
    vector<bool> vis(g.size(),false);
    for(int i=0;i<g.size();i++){
        if(vis[i] == false){
            vis[i] = true;
            dfsUtility(g,vis,i);
        }
    }
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
        dfs(g);
    }
    return 0;
}