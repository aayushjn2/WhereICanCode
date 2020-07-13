#include<bits/stdc++.h>
using namespace std;
vector<int> kahnsAlgo(vector<pair<int,int>> g[],int vertices){
    vector<int> res;
    queue<int> q;
    vector<int> indegree(vertices,0);
    for(int i=0;i<vertices;i++){
        if(indegree[i]==0)q.push(i);
    }
    int count = n;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g[u]){
            indegree[v]-=1;
            if(indegree[v]==0)
                q.push(v);
        }
        res.push_back(u);
        count -=1;
    }
    if(count != 0) return res;
    return new vector<int>;
}
int main(){
    int vertices,edges;cin>>vertices>>edges;
    vector<pair<int,int>> g[vertices];
    for(int edge=0;edge<edges;edge++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    vector<int> topologicalVector = kahnsAlgo(g,vertices);
    if(topologicalVector.empty()){
        cout<<"Graph is not a type of DAG"<<endl;
    }
    else{
        for(auto v: topologicalVector)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}