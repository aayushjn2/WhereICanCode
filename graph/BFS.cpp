//source cormen
/*
    this is the graph traversal approach, that is, BFS

*/
#include<bits/stdc++.h>
using namespace std;
#define WHITE 0 
#define GRAY 1 
#define BLACK 2
#define INF 0xffffff
#define NIL -1
void addEdge(vector<int> G[], int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void showGraph(vector<int> G[],int v){
	for(int i=0;i<v;i++){
		cout<<i<<" -> ";
		for(auto x:G[i])
			cout<<x<<"/";
		cout<<endl;
	}
}
void BFS(vector<int> G[],int s,int v){
	int color[v],d[v],pi[v];
	for(int i=0;i<v;i++){
		if(i!=s){
		color[i]=WHITE;		d[i] = INF;		pi[i] = NIL;}
	}
	color[s]=GRAY;
	d[s]=0;
	pi[s] = NIL;
	queue <int> q;
	q.push(s);
	int last = 0;
	int u;
	while(!q.empty()){
		u = q.front();
		cout<<u<<" ";
		q.pop();
		for(auto v:G[u]){
			if(color[v]==WHITE){
				color[v] = GRAY;
				d[v] = d[u]+1;
				pi[v]=u;
				q.push(v); 
			}
			color[u] = BLACK;
		}
	}
	cout<<endl;
	return ;
}
int main(){
	cout<<"Enter total number of nodes for the graph"<<endl;
	int ver;cin>>ver;
	vector<int> G[ver];
	cout<<"Enter total number of edges for the graph"<<endl;
	int e;cin>>e;
	for(int i=0;i<e;i++){
		int u,v;cin>>u>>v;
		addEdge(G,u,v);
	}
	//showGraph(G,ver);
	BFS(G,0,ver);
	BFS(G,3,ver);
	return 0;
}
