/*
4
4 1 9 8 => 16
8 9 2 1
1 2 8 9
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n){
    sort(a, a + n);
    if(n == 1 || n == 2){
        return a[n-1];
    }
    if(n == 3 )
        return a[0] + a[1] + a[2];
    int min_1 = a[0];
    int min_2 = a[1];
    int res = min_2;
    for(int i = n-1; i>2; i = i - 2){
        res = res + a[i] + 2* min_2 + min_1;
    }
    if(n%2 == 1){
        res = res + a[2];
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }
    return 0;
}