//Source : https://practice.geeksforgeeks.org/problems/count-the-triplets/0
#include<bits/stdc++.h>
using namespace std;

//Complexity : O(n^3)
int bruteForce(vector<int>& a, int n){
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[i]+a[j]==a[k])
                    res++;
            }
        }
    }
    return res;
}

//Complexity : O(n^2)
int usingFrequency(vector<int>& a, int n){
    int max = *max_element(a.begin(),a.end());
    vector<int> freq(max+1,0);
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;
    for (int i = 1; i <= max; i++)  
        ans += freq[0] * freq[i] * (freq[i] - 1) / 2;
    for (int i = 1; 2 * i <= max; i++)  
        ans += freq[i] * (freq[i] - 1) / 2 * freq[2 * i]; 
    for (int i = 1; i <= max; i++) {  
        for (int j = i + 1; i + j <= max; j++)  
            ans += freq[i] * freq[j] * freq[i + j];  
    }
    return ans;
}

//Driver function
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a;int x;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        int res = bruteForce(a,n);
        int res = usingFrequency(a,n);
        cout<<"When brute force method is used,total number of triplets are "<<res<<endl;
    }
    return 0;
}