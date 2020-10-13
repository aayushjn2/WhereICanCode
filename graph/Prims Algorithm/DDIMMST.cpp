#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> iPair; 
long long cal(vector<int> x, vector<int> y,int d){
    long long res  = 0;
    for(int i = 0; i < d;i++){
        res = res + abs(x[i]-y[i]);
    }
    return res;
}
void addEdge(vector <pair<int, int> > adj[], int u,int v, int wt){ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
}
void primMST(vector<pair<int,int> > adj[], int V) {
	priority_queue< iPair, vector <iPair> > pq; 
	int src = 0;
	vector<int> key(V, INT_MIN);
	vector<int> parent(V, -1);
	vector<bool> inMST(V, false);
	pq.push(make_pair(0, src)); 
	key[src] = 0; 
	int res = 0;
	while (!pq.empty()) 
	{
		int u = pq.top().second;  
		if(inMST[u] == false){
          res += pq.top().first;
        }
     	pq.pop();
		inMST[u] = true;
		for (auto x : adj[u]) 
		{ 
			int v = x.first; 
			int weight = x.second;
			if (inMST[v] == false && key[v] < weight) 
			{
				key[v] = weight; 
				pq.push(make_pair(key[v], v)); 
				parent[v] = u; 
			} 
		} 
	} 
	cout<<res<<endl; 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;
    cin>>n>>d;
    vector<vector<int>> points(n, vector<int>(d));
    for(int i = 0; i<n;i++){
        for(int j = 0;j<d;j++){
            cin>>points[i][j];
        }
    }
    vector<iPair > adj[n];
    for(int i = 0; i < n;i++){
        for(int j = i+1;j<n;j++){
            int w = cal(points[i],points[j],d);
            addEdge(adj,i,j,d);
        }
    }
    primMST(adj,n);
    return 0;
}