//complexity will be O(coins.size()*amount)
//NOTE : space will highly depend on amount variable.
#include<bits/stdc++.h>
using namespace std;
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int mem[n+1][amount+1];
    for(int i=0;i<=amount;i++)
        mem[0][i] = 0;
    for(int j=0;j<=n;j++)
        mem[j][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(j-coins[i-1]>=0)
                mem[i][j] = mem[i][j-coins[i-1]] + mem[i-1][j];
            else
                mem[i][j] = mem[i-1][j];
        }
    }
    return mem[n][amount];
}

int main(){
    int amount;cin>>amount;
    int n;cin>n;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        coins.push_back(x);
    }
    cout<<change(amount,coins);
    return 0;
}