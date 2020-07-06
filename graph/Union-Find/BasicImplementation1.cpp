#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
};

class Graph{
    public:
    int V;
    int E;
    Edge *edge;
};

class Subset{
    public:
    int rank;
    int parent;
};

Graph * createGraph(int V, int E){
    Graph * newGraph = new Graph();
    newGraph->V = V;
    newGraph->E = E;
    newGraph->edge = new Edge[sizeof(Edge)*E];
    for(int i=0;i<E;i++){
        int src,dest;cin>>src>>dest;
        newGraph->edge[i].src = src;
        newGraph->edge[i].dest = dest;
    }
    return newGraph;
}
int find(Subset *subset, int i){
    if (subset[i].parent != i) 
        subset[i].parent = find(subset, subset[i].parent); 
    return subset[i].parent;
}

void Union(Subset *subset, int x, int y){
    int xRoot = find(subset, x);
    int yRoot = find(subset, y);
    if (subset[xroot].rank < subset[yroot].rank) 
        subset[xroot].parent = yroot; 
    else if (subset[xroot].rank > subset[yroot].rank) 
        subset[yroot].parent = xroot;
    else{ 
        subset[yroot].parent = xroot; 
        subset[xroot].rank++; 
    }
}
bool isCycle(Graph *graph){
    int V = graph->V;
    int E = graph->E;
    Subset *subset = new Subset[sizeof(Subset)*V];
    for(int v=0;v<V;v++){
        subset[v].parent = v;
        subset[v].rank = 0;
    }
    for(int e=0;e<E;e++){
        int x = find(subset, graph->edge[e].src);
        int y = find(subset, graph->edge[e].dest);
        if(x==y)
            return true;
        Union(subset,x,y);
    }
    return false;
}
