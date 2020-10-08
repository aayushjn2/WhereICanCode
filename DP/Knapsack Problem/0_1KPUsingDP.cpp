//DP
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b){
    return (a>b)?a:b;
}
int usingDP(int W, int value[], int weight[], int n){
    int i,w;
    int mem[n+1][W+1];
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                mem[i][w] = 0; 
            else if (weight[i - 1] <= w) 
                mem[i][w] = max( 
                    val[i - 1] + mem[i - 1][w - weight[i - 1]], 
                    mem[i - 1][w]); 
            else
                mem[i][w] = mem[i - 1][w]; 
        } 
    } 
    return mem[n][W];
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
        cout<<usingDP(W, value, weight, totalValues)<<endl;
    }
    return 0;
}