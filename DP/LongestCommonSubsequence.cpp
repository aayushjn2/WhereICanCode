#include<bits/stdc++.h>
using namespace std;

inline int max(int a,int b){
    return (a>b)?a:b;
}

int longestCommonSubsequence(string a, string b) {
    int x = a.length(), y = b.length();
    int l[2][y+1];
    bool row;
    for(int i=0;i<=x;i++){
        row = i&1;
        for(int j=0;j<=y;j++){
            if(i==0 || j==0)
                l[row][j]=0;
            else if(a[i-1]==b[j-1])
                l[row][j] = l[1-row][j-1]+1;
            else
                l[row][j] = max(l[1-row][j],l[row][j-1]);
        }
    }
    return l[row][y];
}

int main(){
    string a,b;cin>>a>>b;
    cout<<longestCommonSubsequence(a,b)<<endl;
    return 0;
}