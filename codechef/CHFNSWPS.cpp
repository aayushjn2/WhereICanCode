#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;
        int mn = 1e9;
        int checksum = 0;
        map<int,int> mapA,mapB;
        for(int i=0;i<n;i++){
            cin>>x;
            checksum ^=x;
            mapA[x]++;
            mn = min(mn,x);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            checksum ^= x;
            mapB[x]++;
            mn = min(mn,x);
        }
        if(checksum){
            cout<<-1<<endl;
            continue;
        }
        vector<int> a,b;
        for(auto x: mapA){
            int ele = x.first;
            int count = x.second;
            if(mapB.find(ele)!= mapB.end()){
                int dx = min(count, mapB[ele]);
                mapA[ele] -=dx;
                mapB[ele] -=dx;
            }
        }
        for(auto x: mapA){
            int ele = x.first;
            int count = x.second;
            for(int i=0;i<count/2;i++)
                a.push_back(ele);
        }
        for(auto x: mapB){
            int ele = x.first;
            int count = x.second;
            for(int i=0;i<count/2;i++)
                b.push_back(ele);
        }
        long long int res = 0;
        reverse(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            res += min(2*mn,min(a[i],b[i]));
        }
        cout<<res<<endl;
    }
    return 0;
}