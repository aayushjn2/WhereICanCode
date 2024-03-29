#include<bits/stdc++.h>
using namespace std;


//recursive approach
bool subsetProblem(int index, int n, int sum, int a[]){
    if(index == n-1 && sum >0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(sum < a[index]){
        return subsetProblem(index+1,n,sum,a);
    }
    return subsetProblem(index+1,n,sum,a) || subsetProblem(index+1,n,sum-a[index],a);
}

//iterative

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
int main(){

}