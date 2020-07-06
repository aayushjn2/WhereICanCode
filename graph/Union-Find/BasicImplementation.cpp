#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src,dest;
};
class Graph{
    public:
    int V,E;
    Edge* edge;
};
Graph* createGraph(int V, int E){
    Graph *g = new Graph();
    g->V = V;
    g->E = E;
    g->edge = new Edge[g->E*sizeof(Edge)];
    return g;
}
int find(int parent[], int i){
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}
void Union(int parent[], int x, int y){
    int xSet = find(parent,x);
    int ySet = find(parent,y);
    if(xSet != ySet)
        parent[xSet] = ySet;
}

int isCycle(Graph * graph){
    int *parent = new int[graph->V*sizeof(int)];
    memset(parent,-1,sizeof(int)*graph->V);
    for(int i=0;i<graph->E;i++){
        int x = find(parent,graph->edge[i].src);
        int y = find(parent,graph->edge[i].dest);
        if(x==y)return 1;
        Union(parent, x, y);
    }
    return 0;
}
void addEdge(Graph * graph,int index,int src,int dest){
    graph->edge[index].src = src;
    graph->edge[index].dest = dest;
    return;
}
int main()  
{
    int V,E;
    cin>>V>>E; 
    Graph* graph = createGraph(V, E);
    for(int i=0;i<E;i++){
        int src,dest;cin>>src>>dest;
        addEdge(graph,i,src,dest);
    } 
    if (isCycle(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  
    return 0;  
}