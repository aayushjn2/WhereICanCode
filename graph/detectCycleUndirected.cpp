/*
	this is the program to detect the cycle using DFS approach
*/



#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
void addEdge(vector<int> G[],int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
bool DFSVISIT(vector<int> G[],int u,int color[],bool flag,int pi[]){
	color[u] = GRAY;
	for(auto v : G[u]){
		if(color[v]==WHITE){
			pi[v]=u;
			flag=DFSVISIT(G,v,color,flag,pi);
		}
		else if(color[v]!=WHITE && pi[u]!=v){	
			flag = true;
		}
	}
	color[u] = BLACK;
	return flag;
}
bool detectCycle(vector<int> G[],int ver,int color[],bool flag,int pi[]){
	for(int i=0;i<ver;i++){
		color[i] = WHITE;
		pi[i]=-1;
	}
	for(int u = 0;u<ver;u++){
		if(color[u]==WHITE){
			flag = DFSVISIT(G,u,color,flag,pi);
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
