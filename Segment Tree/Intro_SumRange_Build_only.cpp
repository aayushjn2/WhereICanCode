#include <bits/stdc++.h>
using namespace std;
void buildSegmentTree(int arr[],int index,int s, int e, int st[]){
    if (s==e){
        st[index] = arr[s];
        return;
    }
    int mid = s+(e-s)/2;
    buildSegmentTree(arr,2*index+1,s,mid,st);
    buildSegmentTree(arr,2*index+2,mid+1,e,st);
    st[index] = st[2*index+1] + st[2*index+2];
    return;
}
void showSegmentTree(int st[],int max_size){
    for(int i=0;i<max_size;i++)
        cout<<st[i]<<" ";
    cout<<endl;
    return;
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;cout<<max_size<<endl;
    int segmentTree[max_size];
    memset(segmentTree,0,sizeof(segmentTree));
    buildSegmentTree(arr,0,0,n-1,segmentTree);
    showSegmentTree(segmentTree,max_size);
    return 0;
}