#include<bits/stdc++.h>
using namespace std;
inline int max(int a, int b){
    return (a>b)?a:b;
}
int longestPalindromeSubseq(string a) {
    int n=a.length();
    if(n==1)
        return n;
    int L[n][n];
    for(int i=0;i<n;i++)
        L[i][i]=1;
    int i, j, length; 
    for (length=2; length<=n; length++) 
    { 
        for (i=0; i<n-length+1; i++) 
        { 
            j = i+length-1; 
            if (a[i] == a[j] && length == 2) 
                L[i][j] = 2; 
            else if (a[i] == a[j]) 
                L[i][j] = L[i+1][j-1] + 2; 
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
    return L[0][n-1];
}
int main(){
    string s;cin>>s;
    cout<<longestPalindromeSubseq(s)<<endl;
    return 0;
}