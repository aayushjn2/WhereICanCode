#include<bits/stdc++.h>

using namespace std;

bool subsetSumProblem(int a[], int n, int sum){
    bool subset[n+1][sum+1];

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
    return subset[n][sum];  
}

bool findPartition(int a[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    if(sum %2 !=0){
        return false;
    }
    return subsetSumProblem(a,n,sum/2);
}


int main(){

}