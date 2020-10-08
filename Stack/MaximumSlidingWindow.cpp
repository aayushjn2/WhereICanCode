#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> & A){
    stack<int> s;
    int n = A.size();
    vector<int> nge(n);
    s.push(n-1);
    nge[n-1] = n; // take next greater element as length of array if next greater element does not exists
    for(int i = n-2;i>=0;i--){
        while(!s.empty() && A[i] > A[s.top()]){ // pop from stack if current value is greater than top of stack
            s.pop();
        }
        if(s.empty()){
            nge[i] = n; // case when next greater element does not exists
        }
        else{
            nge[i] = s.top(); //  now value for ith index will be top of stack
        }
        s.push(i);
    }
    return nge;
}

int main(){
    int n;cin>>n;
    vector<int> A(n),nge(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int k;cin>>k;
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && A[i] < A[s.top()]){ // check if stack is not empty and ith value > top of the stack
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){// now stack will left with all elements having no greater element
        nge[s.top()] = -1;
        s.pop();
    }
    int j = 0;
    for(int i = 0;i<=n-k;i++){
        if(j<i){
            j = i;
        }
        while(nge[j]< i+k)
            j = nge[j];
        cout<<A[j];
    }
    return 0;
}