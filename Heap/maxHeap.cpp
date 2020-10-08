#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    priority_queue<int, vector<int> > maxHeap;
    while(n--){
        int x; cin>>x;
        maxHeap.push(x);
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    return 0;
}