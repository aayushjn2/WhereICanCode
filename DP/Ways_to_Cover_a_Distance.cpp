#include<bits/stdc++.h>
using namespace std;
int countNumberOfWays(int dist){
    int mem[dist+1];
    mem[0]=mem[1]=1;
    mem[2] = 2;
    for(int i=3;i<=dist;i++)
        mem[i] = mem[i-3] + mem[i-2] + mem[i-1];
    return mem[dist];
}
int main(){
    int dist;cin>>dist;
    cout<<countNumberOfWays(dist);
    return 0;
}