#include<bits/stdc++.h>
using namespace std;


//recursive 
int countsubset(int a[], int i, int n, int sum, int count){
    if(i == n && sum == 0){
        count++;
        return;
    }
    count = countsubset(a,i+1,n,sum,count);
    count = countsubset(a,i+1,n,sum-a[i],count);
    return count;
}

//iterative

int countsubsetIterative(int a[], int n, int sum){
    int subset[n+1][sum+1];

    for(int i=0;i<=n;i++){
        subset[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        subset[0][i] =0;
    }
    subset[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j < a[i-1]){
                subset[i][j] = subset[i-1][j];
            }
            if(j >= a[i-1]){
                subset[i][j] = subset[i-1][j] + subset[i-1][j - a[i-1]];
            }
        }
    }
    return subset[n][sum];
}

int main(){

}