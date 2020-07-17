//LINK TO QUESTION : https://leetcode.com/problems/top-k-frequent-elements/
// TOPIC : HEAP and HASH TABLE
// TIME COMPLEXITY :O(Nlogk)
#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> m;
    int n = nums.size();
    vector<int> res;
    for(int i=0;i<n;i++)
        m[nums[i]]++;
    priority_queue< pair<int,int>, vector< pair<int,int>> > maxHeap;
    for(auto x: m)
        maxHeap.push({x.second,x.first});
    for(int i=0;i<k;i++){
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return res;
}

int main(){
    int n,k;cin>>n>>k;
    vector<int> nums;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;nums.push_back(x);
    }
    vector<int> res = topKFrequent(nums,k);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}