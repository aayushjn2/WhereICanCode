//source cormen
/*
    this is the graph traversal approach, that is, BFS

*/
/*
	this is BFS of a given connected undirected graph.Connected Graph is a graph in which u can
	reach to any vertex from any other vertex,that is,you can start with any node and you will
	be able to reach any node in a graph
*/

#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 0xffffff
#define NIL -1

//check for type of the graph
int checkTypeOfGraph(){
    int typeOfGraph;
    cout<<"Enter 1 for undirected graph and 0 for directed graph";
    cin>>typeOfGraph;
    while(1){
        if(typeOfGraph==1)break;
        else if(typeOfGraph==0)break;
        else{
            cout<<"Enter the valid Choice "<<endl;
            cin>>typeOfGraph;
        }
    }
    return typeOfGraph;
}

//add edge for undirected graph
void addEdgeUndirectedGraph(vector<int> G[], int u,int v){
	
	G[u].push_back(v);
	G[v].push_back(u);
}

//add edge for directed graph
void addEdgeDirectedGraph(vector<int> G[], int u,int v){
	
	G[u].push_back(v);
}

//this method will print the adjacency list
void showGraph(vector<int> G[],int v){
	for(int i=0;i<v;i++){
		cout<<i<<"->";
		vector<int>::iterator j;
		for(j = G[i].begin();j != G[i].end();j++){
			cout<<*j<<"/";
		}
		cout<<endl;
	}
}

// Method BFS 
void BFS(vector<int> G[],int s,int ver, int color[]){
	
	color[s]=GRAY; // it signifies that node has discovered now 
	queue <int> q; //intialising queue
	q.push(s); //current node pushed
	while( !q.empty() ){
		int u = q.front();
		cout<<u<<" ";
		q.pop();
		vector<int>::iterator v;
		for(v = G[u].begin();v!=G[u].end();v++){
			if(color[*v]==WHITE){
				color[*v] = GRAY;
				q.push(*v); //finally pushed into the queue
			}
			color[u] = BLACK;//finally processed
		}
	}
	cout<<endl;
	return ;
}


int main(){
	int typeOfGraph = checkTypeOfGraph();
	// typeOfGraph have 1 for undirected graph and 0 for directed graph
	cout<<"Enter total number of nodes for the graph"<<endl;
	int ver;cin>>ver;
	vector<int> G[ver];
	cout<<"Enter total number of edges for the graph"<<endl;
	int e;cin>>e;
	
	cout<<"Enter each edge "<<endl;
	// add each edge to the graph
	for(int i=0;i<e;i++){
		int u,v;cin>>u>>v;
		if(typeOfGraph)
			addEdgeUndirectedGraph(G,u,v);
		else
			addEdgeDirectedGraph(G,u,v);
	}
	
	showGraph(G,ver);
	int color[ver];
	
	for(int i=0;i<ver;i++){
		color[i] = WHITE;	
	}
	
	for(int i=0;i<ver;i++){
		if(color[i]==WHITE)
			BFS(G,i,ver,color);
	}
	return 0;
}
