#include<bits/stdc++.h>
using namespace std;

int optimalStrategy(int a[],int n){
    int dp[n][n];
    for(int gap = 0; gap<=n;gap++){
        for(int i=0, j=gap; j<n; j++,i++){
            if(gap == 0){
                dp[i][j] = a[i]; 
            }
            else if (gap == 1){
                dp[i][j] = max(a[i],a[j]);
            }
            else{
                int val1 = a[i] + min(dp[i+2][j],dp[i+1][j-1]);
                int val2 = a[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] =max(val1,val2);
            }
        }
    }
    return dp[0][n-1];
}

int main(){

}