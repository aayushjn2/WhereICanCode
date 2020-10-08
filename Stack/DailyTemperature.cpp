//Source : https://leetcode.com/problems/next-greater-element-ii/
// Idea : pop from the stack till top of the stack is less than ith index else push ith index value in the stack
#include<bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperature) {
    int n = temperature.size();
    vector<int> b(n);//array to store result
    stack<int> s;//intialize stack
    for(int i=0;i<n;i++){
        while(!s.empty() && temperature[i] > temperature[s.top()]){ // check if stack is not empty and ith value > top of the stack
            b[s.top()] = i - s.top(); // difference of indexes will give number of days
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){ // now stack will left with all elements having no greater element therefore 
        b[s.top()] = 0; // all elements will have value -1
        s.pop();
    }
    return b;
}

int main(){
    int n;cin>>n;
    vector<int> temperature(n);
    for(int i=0;i<n;i++)
        cin>>temperature[i];
    vector<int> result = dailyTemperatures(temperature);
    for(int i=0;i<n;i++){
        cout<<result<<" ";
    }
    cout<<endl;
    return 0;
}