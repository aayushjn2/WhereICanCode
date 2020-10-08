#include<bits/stdc++.h>
using namepsace std;

int sum(int prefix[], int start, int end){
    if(start==0){
        return prefix[end];
    }
    return prefix[end] - prefix[start-1];
}

int main(){
    int n;cin>>n;
    int a[n],prefix[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0)
            prefix[i]  = prefix[i-1] + a[i];
        else
            prefix[i] = a[i];
    }
    int x  = sum(prefix,i,j);

    cout<<"Sum of array from ith index to jth index"<<x<<endl;
    
    int range[n];
    memset(range,0,sizeof(range));
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int start,end,value;
        cin>>start>>end>>value;
        range[start] = value;
        range[end+1] = -1*value;
    }
    //Calculate prefix array for range array
    for(int i=0;i<n;i++){
        if(i>0)
            prefix[i]  = prefix[i-1] + range[i];
        else
            prefix[i] = range[i];
    }
    return 0;
}
//TESTCASE
//[0 0 0 0 0 0 0 0 0 0]
//1 6 1
//[0 1 0 0 0 0 -1 0 0 0]
//3 7 2
//[0 1 0 2 0 0 -1 -2 0 0]
//2 5 -2
//[0 1 -2 2 2 0 -1 -2 0 0]
//EDGE CASE
// 0 9 -1
//PREFIX ARRAY
[0 1 -1 1 3 3 2 0 0 0]
