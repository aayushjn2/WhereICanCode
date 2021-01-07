#include<bits/stdc++.h>
using namespace std;
void usingset(vector<int> &A, int k){
    set<int> s;
    vector<pair<int,int>> res;
    for(auto val : A){
        if(s.find(k - A[i]) != s.end()){
            res.push_back({A[i],k-A[i]});
        }
        s.insert(A[i]);
    }
    for(auto pair : res)
        cout<<pair.first<<" "<<pair.second<<endl;
}

void bruteForce(vector<int> &A, int k){
    for(int i = 0;i<A.size();i++){
        for(int j = i+1;j<A.size();j++)
            if(A[i] + A[j] == k)
                cout<<A[i]<<" "<<A[j]<<endl;
    }
}

int main(){
    int n;  cin>>n;
    vector<int> A(n);
    for(int i = 0;i<n;i++)
        cin>>A[i];
    int k;  cin>>k;
    findpairs(A,k);
}

/// 3 5 6 2 8 19 0
// k = 8
// x +  y = k
