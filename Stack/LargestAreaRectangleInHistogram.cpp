#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int> rb(n); // next smaller element index on the right 
    stack<int> s;
    s.push(n-1);
    rb[n-1] = n;
    for(int i = n-2;i>=0;i--){
        while(!s.empty() && A[i] < A[s.top()]){
            s.pop();
        }
        if(s.size() == 0){
            rb[i] = n;
        }else{
            rb[i] = s.top();
        }
        s.push(i);
    }
    vector<int> lb(n); //  next smaller element index on the left;
    stack<int> s;
    s.push(0);
    lb[0] = -1;
    for(int i = 1;i<n;i++){
        while(!s.empty() && A[i] < A[s.top()]){
            s.pop();
        }
        if(s.size() == 0){
            lb[i] = -1;
        }else{
            lb[i] = s.top();
        }
        s.push(i);
    }



    int maxArea = 0;
    for(int i=0;i<n;i++){
        int width = rb[i] - lb[i] - 1;
        int area = width * A[i];
        if(area > maxArea)
            maxArea = area;
    }
    cout<<maxArea<<endl;
    return 0;
}