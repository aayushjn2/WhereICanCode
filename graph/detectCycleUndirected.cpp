/*
	Program to detect the cycle using DFS approach
*/
#include<bits/stdc++.h>
using namespace std;
#define WHITE 0 // represents node is not visited
#define GRAY 1 // represents node is discovered
#define BLACK 2 // represents node is visited

//insert edge for undirected graph
void addEdge(vector<int> G[],int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

bool DFSVISIT(vector<int> G[],int u,int color[],bool flag,int pi[]){
	color[u] = GRAY;
	for(auto v : G[u]){
		if(color[v] == WHITE){ // if vertex v is not visited yet
			pi[v] = u; //parent of vertex v is u
			flag = DFSVISIT(G,v,color,flag,pi); //  recursive call for vertex v
		}
		else if(color[v] != WHITE && pi[u] != v){ // if vertex v is either discovered or visited and parent of u is not v
			flag = true; // cycle detected
		}
	}
	color[u] = BLACK;
	return flag;
}
bool detectCycle(vector<int> G[],int ver,int color[],bool flag,int pi[]){
	for(int i=0;i<ver;i++){
		color[i] = WHITE;
		pi[i] = -1;
	}
	for(int u = 0;u<ver;u++){
		if(color[u] == WHITE){
			flag = DFSVISIT(G, u, color, flag, pi);
		}
	}
	return flag;
}
int main(){
	cout<<"Enter the number of vertices and edges for the graph to detect the cycle ";
	int e,ver;cin>>ver>>e;
	int color[ver],pi[ver];
	static bool flag = false;
	vector<int> G[ver];
	cout<<"Now Enter the edges one by one "<<endl;
	for(int i=0;i<e;i++){
		int u,v;cin>>u>>v;
		addEdge(G,u,v);
	}
	flag = detectCycle(G,ver,color,flag,pi);
	if(flag)
		cout<<"cycle detected"<<endl;
	else
		cout<<"cycle is not found"<<endl;
	return 0;
}
