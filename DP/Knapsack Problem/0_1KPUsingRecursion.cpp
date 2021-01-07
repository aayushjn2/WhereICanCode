//brute force
//find sum of each subset 
//find max among all songs
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
    return (a>b)?a:b;
}
int usingRecursionAllSubset(int W, int value[], int weight[], int n){
    if(W==0 || n==0)
        return 0;
    if(weight[n-1]>W)
        return usingRecursionAllSubset(W, value, weight, n-1);
    else
        return max(
            value[n-1] + usingRecursionAllSubset(W-weight[n-1], value, weight, n-1),
            usingRecursionAllSubset(W, value, weight, n-1)
        );
}

int main(){
    int testCases;cin>>testCases;
    while(testCases--){
        int totalValues;cin>>totalValues;
        int value[totalValues];
        int weight[totalValues];
        for(int i=0;i<totalValues;i++){
            cin>>value[i];
        }
        for(int i=0;i<totalValues;i++){
            cin>>weight[i];
        }
        int W;cin>>W;
        cout<<usingRecursionAllSubset(W, value, weight, totalValues)<<endl;
    }
    return 0;
}