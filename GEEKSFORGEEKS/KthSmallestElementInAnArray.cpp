#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int a[],int n, int k){
    priority_queue<int> q;
    for(int i=0;i<k;i++){
        q.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]<q.top()){
            q.pop();
            q.push(a[i]);
        }
    }
    return q.top();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;cin>>k;
	    int val = kthSmallestElement(a,n,k);
	    cout<<val<<endl;
	}
	return 0;
}