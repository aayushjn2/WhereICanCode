#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define mp make_pair
typedef pair<int,int> iPair;
typedef pair<long long, long long> lPair;

//Function that adds edge in the  graph
void addEdge(vector< pair<int,int> > g[], int u, int v, int wt){
    g[u].push_back(mp(v,wt));
    g[v].push_back(mp(u,wt));
}

//Function that calculates the shortest path from a given node to all nodes
vector<iPair> shortestPath(vector< pair<int,int> > g[],int V,int source){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    vector<int> dist(V, INF); 
    pq.push(make_pair(0, source)); 
    dist[source] = 0;
    while (!pq.empty()){ 
        int u = pq.top().second; 
        pq.pop(); 
        for (auto x : g[u]) {
            int v = x.first; 
            int weight = x.second;
            if (dist[v] > dist[u] + weight) 
            {
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    vector<iPair> res;
    for(int i=0;i<V;i++){
        res.push_back(mp(i,dist[i]));
    }
    return res;
}

int main(){
    cout<<"Enter vertices and edges for a undirected graph"<<endl;
    int vertices;cin>>vertices;
    int edges;cin>>edges;
    vector<iPair > g[vertices];
    cout<<"Now,enter each edge with weight in the following format staring vertex, ending vertex and weight"<<endl;
    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(g,u,v,wt);
    }
    cout<<"Now enter vertex for which you want to find shortes distance to all other nodes"<<endl;
    int source;cin>>source;
    vector<iPair> res = shortestPath(g,vertices,source);
    cout<<"Destination Vertex | Distance"<<endl;
    for(auto x: res){
        cout<<x.first<<" | "<<x.second<<endl;
    }
    return 0;
}