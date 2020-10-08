//Source : https://leetcode.com/problems/next-greater-element-ii/

#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> b(n);//array to store result
    stack<int> s;//intialize stack
    for(int i=0;i<2*n;i++){
        if(!s.empty() && nums[i%n]>nums[s.top()]){
            while(!s.empty() && nums[i%n] > nums[s.top()]){
                b[s.top()] = nums[i%n];s.pop();
            }
        }
        if(i<n)
            s.push(i%n);
    }
    while(!s.empty()){
        b[s.top()] = -1;
        s.pop();
    }
    return b;
}

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> result = nextGreaterElements(nums);
    for(int i=0;i<n;i++){
        cout<<result<<" ";
    }
    cout<<endl;
    return 0;
}