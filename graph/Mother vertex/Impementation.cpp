#include<bits/stdc++.h>
using namespace std;
int findMotherVertex(vector<int> g[],int vertices){
    int possibleMotherVertex = dfs(g,vertices);
    cout<<"possibleMotherVertex "<<possibleMotherVertex<<endl;
    bool check = dfsUtil(g,vertices,possibleMotherVertex);
    cout<<"Check "<<check<<endl;
    if(check)
        return possibleMotherVertex;
    else
        return -1;
}
int main(){
    int vertices,edges;cin>>vertices>>edges;
    vector<int> g[vertices];
    for(int edge=0;edge<edges;edge++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    int motherVertex = findMotherVertex(g, vertices);
    if(motherVertex == -1){
        cout<<"Mother vertex does not exists"<<endl;
    }
    else{
        cout<<"Mother vertex present in graph and it is "<<motherVertex<<endl;
    }
    return 0;
}