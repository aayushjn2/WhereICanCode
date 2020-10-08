#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n;cin>>n;
    while(n--){
        int x;cin>>x;
        minHeap.push(x);
    }
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    return 0;
}