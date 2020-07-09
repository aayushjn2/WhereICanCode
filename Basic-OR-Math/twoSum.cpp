#include<bits/stdc++.h>
using namespace std;
//complexity is O(n^2)
//checking for each pair
vector<pair<int,int>> pairSum(int a[], int n, int ts){
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==ts)
                res.push_back({a[i],a[j]});
        }
    }
    return res;
}



int main(){
    int n;cin>>n;
    int ts;cin>>ts;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<pair<int,int>> res = pairSum(a,n,ts);
    for(auto x: res){
        cout<<"("<<x.first<<", "<<x.second<<")"<<endl;
    }
    return 0;
}