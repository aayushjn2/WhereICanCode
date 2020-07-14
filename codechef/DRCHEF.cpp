#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        long long int x,a;cin>>n>>x;
        long long maxP = -1;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>maxP)maxP=a;
        }
        long long res=0;
        long long int temp = maxP;
        while(maxP>0){
            cout<<maxP<<"-"<<x<<endl;
            maxP -=x;
            x *=2;
            maxP *=2;
            if(maxP>temp)maxP=temp;
            res++;
        }
        cout<<res<<endl;
        cout<<res+n-1<<endl;
    }
    return 0;
}