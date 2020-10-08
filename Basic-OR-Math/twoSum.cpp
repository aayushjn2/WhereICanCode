#include<bits/stdc++.h>
using namespace std;
//problem statement :  Given an array A[] and a number x, check for pair(s) in A[] with sum as x
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

"""
//algo
    1. sort array in increasing order | time complexity : O(NlogN) 
    2. declare two variable left = 0 and right = n - 1 (where size of array is n) | time complexity : O(1) 
    3. loop till left < right | time complexity : O(N) 
    4. if( A[left] + A[right] == targetSum) : one pair found, increment left by 1 and decrement right by 1 | time complexity : O(1) 
    5. else if (A[left] + A[right] < targetSum) : increment left by 1 | time complexity : O(1) 
    6. else : decrement right by 1 | time complexity : O(1)
//complexity : O(nlogn)
"""
vector<pair<int,int>> pairSum_1(int a[], int n, int ts){
    sort(a, a + n);
    vector<pair<int,int>> res;
    int left = 0, right = n - 1;
    while(left < right){
        if(a[left] + a[right] == ts){
            res.push_back(a[left], a[right]);
            left ++;
            right --;
        }
        else if( a[left] + a[right] < ts){
            left ++;
        }
        else{
            right --;
        }
    }
    return res;
}


"""
This problem can be solved efficiently by using the technique of hashing.
Use a hash_map to check for the current array value x(let),
if there exists a value target_sum-x which on adding to the former gives target_sum.
This can be done in constant time.
Algo : 
    1. Initialize an empty hash table s.
    2. Do following for each element A[i] in A[] 
        1. If s[x – A[i]] is set then print the pair (A[i], x – A[i])
        2. Insert A[i] into s.
Time and space complexity : O(n)
"""

vector<pair<int,int>> pairSum_2(int a[], int n, int ts){
    unordered_set<int> S;
    vector<pair<int,int>> res;
    for(int i = 0; i<n ;i++){
        if(S.find(ts - a[i]) != S.end()){
            res.push_back({a[i],ts - a[i]});
        }
        S.insert(a[i]);
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
    cout<<"Total number of pairs having sum "<< ts <<" is/are "<< res.size() <<endl;

    for(auto x: res){
        cout<<"("<<x.first<<", "<< x.second <<")"<<endl;
    }
    return 0;
}