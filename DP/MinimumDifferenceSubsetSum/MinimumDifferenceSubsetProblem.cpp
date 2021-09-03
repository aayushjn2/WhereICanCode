#include<bits/stdc++.h>
using namespace std;

bool subsetSumProblem(int a[], int n, int sum){
    bool subset[n+1][sum+1];
    int sum =0;
    for(int i=0;i<n;i++){
        sum +=a[i];
    }
    for(int i=0;i<=n;i++){
        subset[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        subset[0][i] =false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j < a[i-1]){
                subset[i][j] = subset[i-1][j];
            }
            if(j >= a[i-1]){
                subset[i][j] = subset[i-1][j] || subset[i-1][j - a[i-1]];
            }
        }
    }
    int diff = INT_MAX;
    for(int i=0;i<sum/2;i++){
        if(subset[i][n] == true)
            diff = min(diff, sum - 2*i);
    }
    
    return diff;
}