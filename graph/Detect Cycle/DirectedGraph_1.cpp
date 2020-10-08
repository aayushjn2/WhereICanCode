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
bool isCylic_util(vector<vector<int>>& g, vector<bool>& visited, int u){
    if(visited[u] == true){
        return true;
    }
    visited[u] = true;
    bool flag = false;
    for(int v = 0;v<g[u].size();v++){
        flag = isCylic_util(g,visited,g[u][v]);
        if(flag == true){
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<vector<int>>& g, int vertices){
    vector<bool> visited(vertices,false);
    bool flag = false;
    for(int i=0;i<vertices;i++){
        visited[i] = true;
        for(int j=0;j<g[i].size();j++){
            flag = isCylic_util(g,visited,g[i][j]);
            if(flag == true){
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
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
    }
    return 0;
}