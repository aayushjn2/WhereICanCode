//https://leetcode.com/problems/product-of-array-except-self/
// Time Complexity : O(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0] = nums[0];
    suffix[n-1] = nums[n-1];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]*nums[i];
        suffix[n-i-1] = suffix[n-i]*nums[n-i-1];
    }
    vector<int> res(n);
    res[0] = suffix[1];
    res[n-1] = prefix[n-2];
    for(int i=1;i<n-1;i++){
        res[i] = prefix[i-1]*suffix[i+1];
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> res = productExceptSelf(nums);
    return 0;
}