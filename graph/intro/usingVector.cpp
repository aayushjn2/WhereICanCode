#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> G[], int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void showGraph(vector<int> G[],int v){
	for(int i=0;i<v;i++){
		cout<<i<<" -> ";
		///we can use this also 
		/*
			vector<int>::iterator j;
		for(j = G[i].begin();j!=G[i].end();j++)
			cout<<"->"<<*j;
		*/
		///
		for(auto x:G[i])
			cout<<x<<"/";
		cout<<endl;
	}
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
	showGraph(G,ver);
	return 0;
}
